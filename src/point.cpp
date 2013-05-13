/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//implementation of a class for storing and using cartesian coordinates

#include "swarm_includes.h"
#include "point.h"

void pt::set(qreal x_, qreal y_){
	x=x_;
	y=y_;
}

//scale vector to a given magnitude
pt & pt::magnitude(qreal n){
	qreal mag=std::sqrt(x*x+y*y);
	if(mag!=0){
		x=x*n/mag;
		y=y*n/mag;
	}
	return *this;
}

pt & pt::operator=(pt const & p){
	x=p.x;
	y=p.y;
	return *this;
}

pt & operator+=(pt & p1, pt const & p2){
	p1.x+=p2.x;
	p1.y+=p2.y;
	return p1;
}

pt operator+(pt const & p1, pt const & p2){
	return pt(p1.x+p2.x,p1.y+p2.y);
}

pt operator-(pt const & p1, pt const & p2){
	return pt(p1.x-p2.x,p1.y-p2.y);
}

pt operator*(pt const & p1, pt const & p2){
	return pt(p1.x*p2.x,p1.x*p2.y);
}

pt operator*(qreal num, pt const & p){
	return pt(num*p.x, num*p.y);
}

//generate a random point
pt randPt(){
	qreal i(qrand());
	pt point(i*std::sin(i),i*std::cos(i));
	return point;
}

//distance between to points
qreal distance(pt p1, pt p2){
	return std::sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
