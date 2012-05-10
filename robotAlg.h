/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//header bor the robotAlg functor
//describes how robots behave and provides
//allows for gui to modify behavior dynamically

#ifndef ROBOTALG_H
#define ROBOTALG_H

#include "includes.h"
#include "robot.h"
#include "box.h"

//sets direction and knowledge state of a robot
//contains bools for wich algorithms to run on the robot
//allows for dynamic control of robot behavior
class robot;
class pileInfo;

class robotAlg{
public:
	robotAlg(qreal depreciation_=1.0, bool pick_up_=true,
	bool box_drop_=true, bool robots_drop_=true,
	bool secondary_box_=true, bool avoid_bot_=true,
	bool congregate_color_=true, bool random_dir_=true,
	bool pile_size_=true, bool pile_loc_=true,
	bool impurity_count_=true, unsigned control_type_=0);

	//functor, called by robots forall behavior
	void operator() (robot & curr);

	//flags for which algorithms to use
	bool pick_up;
	bool box_drop;
	bool robots_drop;
	bool secondary_box;
	bool avoid_bot;
	bool congregate_color;
	bool random_dir;
	bool pile_size;
	bool pile_loc;
	bool impurity_count;
	qreal depreciation;
	unsigned control_type; //0,1,2 used to set control method

	//functions for world to set up the behavior algorithm
	void setColor(unsigned color_num_){ color_num=color_num_; }
	void setRobots(std::vector<robot*> & robots_){robots=&robots_;}
	void setBoxes(std::vector<box*> & boxes_) { boxes=&boxes_; }
	void setPile(unsigned size) {
			central_pile.clear();
			central_pile.resize(size);
	}
	void setWidth(unsigned width_){width=width_;}
	void setHeight(unsigned height_){height=height_;}

private:
	//algorithms
	void findNear(robot & curr);
	void managePiles(robot & curr);
	void setVars(robot & curr);
	void runBehavior(robot & curr);
	void sensorColor(robot & curr);
	bool secondaryBox(unsigned & index);
	bool visSameColor(robot const & curr, unsigned & index);
	bool visSameColorBox(robot const & curr, unsigned & index);
	//behaviors
	bool avoidWalls(robot & curr);
	void pickUp(robot & curr, unsigned index);
	void boxDrop(robot & curr);
	void avoidBot(robot & curr);
	void approach(robot & curr, pt loc);
	void randomDir(robot & curr);
	//logic functions
	bool pickUpPile(robot & curr, unsigned index);
	bool dropPile(robot & curr, int shift);
	bool approachMemPile(robot & curr);

	//world info
	std::vector<robot*> * robots;
	std::vector<box*> * boxes;
	std::vector<robot*> robot_found;
	std::vector<box*> box_found;
	std::vector<pileInfo> central_pile;
	unsigned color_num;
	//graphical properties
	unsigned width, height;
};

#endif
