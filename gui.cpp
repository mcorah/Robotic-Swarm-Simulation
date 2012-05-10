/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//implementation of the gui for the swarm simulation
//the gui itself is described in the swarm_world.ui file, created with qt creator

#include "includes.h"
#include "gui.h"
#include "swarm_world.h"


swarm_gui::swarm_gui()
:field(NULL), world(NULL), alg(0.9995)
{
	//basic setup
	Ui_main_window::setupUi(this);

	run_clock=new QTimer(this);

	//run, continuous
	connect(run_button, SIGNAL(clicked()),this,SLOT(run()));
	connect(run_clock, SIGNAL(timeout()), this, SLOT(step()));
	//step run
	connect(step_button, SIGNAL(clicked()),this,SLOT(step()));
	//generate
	connect(generate_button, SIGNAL(clicked()),this,SLOT(generate()));
	//dynamic speed control
	connect(play_speed, SIGNAL(sliderReleased()),this, SLOT(updateSpeed()));
	//behavior controls
	connect(check_pick_up, SIGNAL(stateChanged(int)),this,SLOT(pickUp(int)));
	connect(check_box_drop, SIGNAL(stateChanged(int)),this,SLOT(boxDrop(int)));
	connect(check_robots_drop, SIGNAL(stateChanged(int)),this,SLOT(robotsDrop(int)));
	connect(check_secondary_box, SIGNAL(stateChanged(int)),this,SLOT(secondaryBox(int)));
	connect(check_avoid_bot, SIGNAL(stateChanged(int)),this,SLOT(avoidBot(int)));
	connect(check_congregate_color, SIGNAL(stateChanged(int)),this,SLOT(congregateColor(int)));
	connect(check_random_dir, SIGNAL(stateChanged(int)),this,SLOT(randomDir(int)));
	//constructive behavior controls
	connect(check_pile_size, SIGNAL(stateChanged(int)),this,SLOT(pileSize(int)));
	connect(check_pile_loc, SIGNAL(stateChanged(int)),this,SLOT(pileLoc(int)));
	connect(check_impurity_count, SIGNAL(stateChanged(int)),this,SLOT(impurityCount(int)));
	//control type
	connect(radio_standard, SIGNAL(clicked(bool)),this,SLOT(standardPiles(bool)));
	connect(radio_shared, SIGNAL(clicked(bool)),this,SLOT(sharedPiles(bool)));
	connect(radio_central, SIGNAL(clicked(bool)),this,SLOT(centralPiles(bool)));
	
}

//for continuous run, start a timer to call the step function at time intervals
void swarm_gui::run(){
	if(!world) generate();
	if(run_clock->isActive()){
		run_clock->stop();
	}else run_clock->start(30/play_speed->value()); 
}

//step the simulation once
//this can be called explicitly or by the timer under continuous run
void swarm_gui::step(){
	if(!world) generate();
	std::cout << "Stepping world\n";
	//stop the clock if the world says it is done
	//stepping can still be done manually
	if(!world->step()){
		run_clock->stop();
	}
	iteration->setNum(world->countItr());
}


void swarm_gui::generate(){
	std::cout << "Generating world\n";
	//delete old world
	run_clock->stop();
	if(field) delete field;
	if(world) delete world;

	//prepare new visual field
	field= new QGraphicsScene(graphics_field->frameRect().width(),
		graphics_field->frameRect().height(), 0, 0);
	graphics_field->setScene(field);
	field->setItemIndexMethod(QGraphicsScene::NoIndex);

	//generate a new world to use the graphicsScene and populate with robots and boxes
	world=new swarm_world(graphics_field->frameRect().width(), graphics_field->frameRect().height(),
		spin_bots->value(), spin_radius->value(), spin_boxes->value(),
		spin_colors->value(), alg, field);
}

//change the time interval for continuous run based on the slider
void swarm_gui::updateSpeed(){
	//only reset the clock if already running, otherwise handled by run function
	if(run_clock->isActive()){
		run_clock->stop();
		run_clock->start(30/play_speed->value());
	}
}

//behavior toggles
//these all set flags within the robotAlg to change robot behavior in real time

//basic toggles
void swarm_gui::pickUp(int state){ alg.pick_up=state; }
void swarm_gui::boxDrop(int state){ alg.box_drop=state; }
void swarm_gui::robotsDrop(int state){ alg.robots_drop=state; }
void swarm_gui::secondaryBox(int state){ alg.secondary_box=state; }
void swarm_gui::avoidBot(int state){ alg.avoid_bot=state; }
void swarm_gui::congregateColor(int state){ alg.congregate_color=state; }
void swarm_gui::randomDir(int state){ alg.random_dir=state; }
//constructive behavior toggles
void swarm_gui::pileSize(int state){ alg.pile_size=state; }
void swarm_gui::pileLoc(int state){
	alg.pile_loc=state;
	//deactivate control type buttons when tracking disabled
	radio_standard->setCheckable((bool)state);
	radio_shared->setCheckable((bool)state);
	radio_central->setCheckable((bool)state);
	radio_standard->update();
	radio_shared->update();
	radio_central->update();
}
void swarm_gui::impurityCount(int state){ alg.impurity_count=state; }
//control type
//select which method is used for pile tracking
void swarm_gui::standardPiles(bool checked){ if(checked) alg.control_type=0; }
void swarm_gui::sharedPiles(bool checked){ if(checked) alg.control_type=1; }
void swarm_gui::centralPiles(bool checked){ if(checked) alg.control_type=2; }
