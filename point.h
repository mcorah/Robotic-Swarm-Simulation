/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//header for a point class used throughout the simulation
//contains relevant operators and other functions

#ifndef PT_H
#define PT_H

#include "includes.h"

class pt{
public:
	pt()
	:x(0), y(0){}

	pt(qreal x_, qreal y_)
	:x(x_), y(y_) {}
	
	pt(pt const & p)
	:x(p.x), y(p.y) {}

	void set(qreal x_, qreal y_);
	pt & magnitude(qreal n);
	pt & operator=(pt const & p);

	qreal x;
	qreal y;
};

pt & operator+=(pt & p1, pt const & p2);
pt operator+(pt const & p1, pt const & p2);
pt operator-(pt const & p1, pt const & p2);
pt operator*(pt const & p1, pt const & p2);
pt operator*(qreal num, pt const & p);

pt randPt();

qreal distance(pt p1, pt p2);

#endif
