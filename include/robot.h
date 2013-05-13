/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//header for robot class

#ifndef ROBOT_H
#define ROBOT_H

#include "swarm_includes.h"
#include "knowledgeItem.h"
#include "pileInfo.h"
#include "point.h"
#include "box.h"
#include "robotAlg.h"

class robot{
public:
	robot(pt loc_, qreal rad_, std::vector<QColor*> & colors_,
	robotAlg & alg_, QGraphicsScene * field_);

	//behavior algorithm needs to be able to modify the robot
	friend class robotAlg;

	void updateState();
	void updatePos();
	void copyInfo();
private:
	std::vector<QColor*> & colors;
	//physical properties
	qreal rad;
	robotAlg & alg;
	//condition
	pt loc;
	pt dir;
	box * curr_box;
	box * avoid_box;

	//used only for coloring sensor circle, not by other robots
	int color_sensor;
	int color_sensor_n;

	//robt knowledge
	std::vector<pileInfo> piles;
	knowledgeItem has_box;
	knowledgeItem box_vis;
	knowledgeItem bot_vis;

	//graphical properties
	QGraphicsScene * field;
	QGraphicsEllipseItem * sensor;
	QGraphicsEllipseItem * body;
};

#endif
