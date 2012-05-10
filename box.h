/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//header for box class
//handles position and graphical properties

#ifndef BOX_H
#define BOX_H

#include "includes.h"
#include "point.h"

class box{
public:
	box(pt loc_, QColor const * color_, int color_num_,
		QGraphicsScene * field_);

	friend class robotAlg;

	void update();
	box * pickUp();
	void drop(pt loc_);
	bool taken();
	const pt & getLoc() const {return loc;}
private:
	pt loc;
	bool visible;
	const int color_num;
	const QColor * color;
	QGraphicsRectItem * rectangle;
	QGraphicsScene * field;
};

#endif
