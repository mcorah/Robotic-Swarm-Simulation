/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//implementation of the box class

#include "includes.h"
#include "box.h"
#include "point.h"

//constructor, creates graphical box
box::box(pt loc_, QColor const * color_, int color_num_, QGraphicsScene * field_)
:loc(loc_), visible(true), color_num(color_num_), color(color_), field(field_)
{
rectangle=field->addRect(loc.x-5,loc.y-5,10,10,QPen(),QBrush(*color,Qt::SolidPattern));
}

//update graphical component of box
void box::update(){
	if(rectangle->isVisible()!=visible){
		rectangle->setRect(loc.x-5,loc.y-5,10,10);
		rectangle->setVisible(visible);
	}
}

//called by robot wanting to pick up the box
box * box::pickUp(){
	visible=false;
	return this;
}

//called by a robot that is dropping the box
void box::drop(pt loc_){
	loc.x=loc_.x;
	loc.y=loc_.y;
	visible=true;
}

//returns whether a robot already has the box
bool box::taken(){
	return !visible;
}
