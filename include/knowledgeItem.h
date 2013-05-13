/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//knowledge
//class to represent robot knowledge
//all robot knowledge is based on whether a property is true
//and an accompanying color
//old and new information is kept separate

#ifndef KNOWLEDGEITEM_H
#define KNOWLEDGEITEM_H

class knowledgeItem{
public:
	knowledgeItem(bool state_, int color_)
	:state_n(state_), color_n(color_), state(state_), color(color_) {}

	void update(){
		state=state_n;
		color=color_n;
	}

	bool state_n;
	int color_n;
	bool state;
	int color;
};

#endif
