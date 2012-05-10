/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//header file describing the gui
//describes basics of use of interface

#ifndef GUI_H
#define GUI_H

#include "includes.h"
#include "ui_swarm_gui.h"
#include "swarm_world.h"

class swarm_gui: public QMainWindow, private Ui::main_window{
	Q_OBJECT
public:
	swarm_gui();

public slots:
	void run();
	void step();
	void updateSpeed();
	void generate();

	//behavior control slots
	void pickUp(int state);
	void boxDrop(int state);
	void robotsDrop(int state);
	void secondaryBox(int state);
	void avoidBot(int state);
	void congregateColor(int state);
	void randomDir(int state);
	//constructive behaviors
	void pileSize(int state);
	void pileLoc(int state);
	void impurityCount(int state);
	//control type, radio buttons
	void standardPiles(bool checked);
	void sharedPiles(bool checked);
	void centralPiles(bool checked);

private:
	QGraphicsScene * field;
	swarm_world * world;
	QTimer * run_clock;
	robotAlg alg; //behavior algorithm modified by guis
};

#endif
