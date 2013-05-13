/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//implementation of swarm_world a wrapper for robot world

#include "swarm_includes.h"
#include "swarm_world.h"
#include "point.h"
#include "robot.h"
#include "robotAlg.h"

//the constructor handles setup of the field
swarm_world::swarm_world(int width_, int height_, int robot_num, int robot_rad, int box_num, int color_num_, robotAlg & alg_, QGraphicsScene * field_)
:height(height_), width(width_), iteration(0), field(field_), color_num(color_num_), alg(alg_)
{
	//set up algorithm
	alg.setRobots(robots);
	alg.setBoxes(boxes);
	alg.setColor(color_num);
	alg.setPile(color_num);
	alg.setWidth(width);
	alg.setHeight(height);

	//seed rand
	qsrand(QTime::currentTime().msec());

	//generate a random set of colors
	generateColors(color_num);

	//invisible rectangles help used to center the visual field on the playing area
	field->addRect(0,0,1,1,QPen(QColor(0,0,0,0)),QBrush(QColor(0,0,0,0)));
	field->addRect(width-1,height-1,1,1,QPen(QColor(0,0,0,0)),QBrush(QColor(0,0,0,0)));

	//find dimension of columns of robots for the grid
	int dim=std::sqrt(1.0*robot_num);
	if(dim*dim<robot_num) ++dim;

	robot * temp_robot;
	box * temp_box;
	//generate boxes
	//note that colors form an alternating sequence
	for(int i=0;i<box_num;++i){
		//create and store box
		temp_box=new box(pt(qrand()%(width-2*(robot_rad+3))+robot_rad+3,
			qrand()%(height-2*(robot_rad+3))+robot_rad+3), colors[i%color_num],
			i%color_num, field);
		boxes.push_back(temp_box);
	}
	int total_bots(0); //total robots in grid
	qreal spacing=2*height/(3*dim);
	//create robots, moving through grid until total number completed
	for(qreal i=-dim/2;i < dim/2+dim%2;++i){
		for(qreal j=-dim/2;j < dim/2+dim%2;++j){
			if(total_bots++<robot_num){
				//create and store robot
				temp_robot=new robot(pt(width/2+spacing*j,height/2+spacing*i),
					robot_rad, colors, alg, field);
				robots.push_back(temp_robot);
			}
		}
	}
}

//basic function to step the world
bool swarm_world::step(){
	std::cout << "running simulation\n";
	//run the behavior function for each robot
	for(unsigned i=0;i<robots.size();++i){
		//std::cout << i;
		robots[i]->updateState();
		//std::cout << std::endl;
	}
	//update position and graphic for each robot
	//the direction is set previously by the behavior algorithm
	for(unsigned i=0;i<robots.size();++i){
		robots[i]->updatePos();
	}
	//update graphics for each box
	for(unsigned i=0;i<boxes.size();++i){
		boxes[i]->update();
	}
	//redraw the screen
	field->update(0,0,width,height);
	++iteration;
	return !isDone(); //checks bounding box for each color
}

//generate a set of random colors plus black based on number of colors to be used
void swarm_world::generateColors(int n){
	QColor * temp;
	for(int i=0;i<n;++i){
		temp = new QColor(qrand()%256, qrand()%256, qrand()%256);
		colors.push_back(temp);
	}
	temp= new QColor(0,0,0);
	colors.push_back(temp);
}

//checks bounding box for each color of box
//if height and width are within 30 the simulation is stopped
//this only stops continuous run
//return true when done
bool swarm_world::isDone() const{
	pt min, max; //min and max x,y values
	//iterate through each color and check each bounding box
	for(int i=0;i<color_num;++i){
		min=max=boxes[i]->getLoc();
		//iterate through all boxes of a given color
		//uses the fact that colors alternate in the vector
		for(int j=i+color_num;j<boxes.size();j+=color_num){
			if(min.x>boxes[j]->getLoc().x) min.x=boxes[j]->getLoc().x;
			else if(max.x<boxes[j]->getLoc().x) max.x=boxes[j]->getLoc().x;
			if(min.y>boxes[j]->getLoc().y) min.y=boxes[j]->getLoc().y;
			else if(max.y<boxes[j]->getLoc().y) max.y=boxes[j]->getLoc().y;
		}
		if(max.x-min.x>30 || max.y-min.y>30) return false;
	}
	return true;
}
