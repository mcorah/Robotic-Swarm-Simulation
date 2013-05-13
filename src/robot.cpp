/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//implementation of robot class for the swarm simulation

#include "swarm_includes.h"
#include "robot.h"
#include "box.h"

//constructor
robot::robot(pt loc_, qreal rad_, std::vector<QColor*> & colors_,
	robotAlg & alg_, QGraphicsScene * field_)
	:colors(colors_), rad(rad_), alg(alg_),
	//state
	loc(loc_), dir(0,0), curr_box(NULL), avoid_box(NULL),
	color_sensor(colors.size()-1), color_sensor_n(colors.size()-1),
	piles(colors_.size()-1),
	//knowledgeItems
	has_box(false,colors.size()-1), box_vis(false,colors.size()-1),
	bot_vis(false,colors.size()-1),
	//graphics
	field(field_), sensor(NULL), body(NULL)
{
	sensor=field->addEllipse(loc.x-rad,loc.y-rad,2*rad,2*rad);
	body=field->addEllipse(loc.x-3,loc.y-3,6,6,QPen(),QBrush(*colors.back(), Qt::SolidPattern));
}

//run the behavior algorithm
void robot::updateState(){
	alg(*this);
}

//update the position and graphics of the robot
void robot::updatePos(){
	loc+=dir;
	//sensor color
	if(color_sensor!=color_sensor_n){
		field->removeItem(sensor);
		//delete sensor;
		sensor=field->addEllipse(loc.x-rad,loc.y-rad,2*rad,2*rad,QPen(*colors[color_sensor_n]),
			QBrush(QColor(255,255,255,0)));
	}else sensor->setRect(loc.x-rad,loc.y-rad,2*rad,2*rad);
	//body color
	if(has_box.color!=has_box.color_n){
		//delete body;
		field->removeItem(body);
		body=field->addEllipse(loc.x-3,loc.y-3,6,6,QPen(),
			QBrush(*colors[has_box.color_n], Qt::SolidPattern));
	}else body->setRect(loc.x-3,loc.y-3,6,6);
	//copies new knowledge to old
	copyInfo();
}

//copy over new components of each knowledge item to old
void robot::copyInfo(){
	color_sensor=color_sensor_n;
	has_box.update();
	box_vis.update();
	bot_vis.update();
}
