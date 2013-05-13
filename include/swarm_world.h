/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//header for the wrapper class swarm_world
//contain robots, boxes, and the general interface

#ifndef SWARM_WORLD_H
#define SWARM_WORLD_H

#include "robot.h"
#include "robotAlg.h"
#include "box.h"
#include "point.h"
#include "swarm_includes.h"

class swarm_world {
public:
	swarm_world(int width_, int height_, int robot_num,
		int robot_rad, int box_num, int color_num_,
		robotAlg & alg, QGraphicsScene * field);

	bool step();
	int countItr(){ return iteration; }
private:
	bool isDone() const;
	void generateColors(int n);

	int height, width; //height and width of robot world
	int iteration;
	QGraphicsScene * field;
	std::vector<robot*> robots;
	std::vector<box*> boxes;

	int color_num; //number of colors being used, minus black
	std::vector<QColor*> colors;

	robotAlg & alg; //behavior algorithm, passed to robots
};

#endif
