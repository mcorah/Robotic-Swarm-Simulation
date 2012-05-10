/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//class to store knowledge about piles of boxes
//used by robot and robotAlg

#ifndef PILEINFO_H
#define PILEINFO_H

#include "point.h"

class pileInfo{
public:
	pileInfo() :max(0),
	temp(0),loc_good(false) {}

	//update size and location of pile if necessary
	void update(pt loc_){
		if(temp>=max){
			if(temp>=2){
				max=temp;
				loc_good=true;
				loc=loc_;
			}
		}
	}

	//use another pile for max and location
	void setMax(pileInfo const & pile){
		loc_good=pile.loc_good;
		max=pile.max;
		loc=pile.loc;
	}

	qreal max;
	qreal depreciation;
	int temp;
	bool loc_good;
	pt loc;
};

#endif
