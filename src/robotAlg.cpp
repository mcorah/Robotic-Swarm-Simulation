/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//implementation of the algorithm for robot behavior

#include "swarm_includes.h"
#include "robot.h"
#include "pileInfo.h"
#include "box.h"
#include "point.h"

robotAlg::robotAlg(qreal depreciation_, bool pick_up_, bool box_drop_, bool robots_drop_,
	bool secondary_box_, bool avoid_bot_, bool congregate_color_, bool random_dir_,
	bool pile_size_, bool pile_loc_, bool impurity_count_, unsigned control_type_)
//set initial states of flags
:pick_up(pick_up_), box_drop(box_drop_), robots_drop(robots_drop_),
	secondary_box(secondary_box_), avoid_bot(avoid_bot_),
	congregate_color(congregate_color_), random_dir(random_dir_),
	pile_size(pile_size_), pile_loc(pile_loc_), impurity_count(impurity_count_),
	depreciation(depreciation_), control_type(control_type_),

	//these will be set later by the swarm_world
	robots(NULL), boxes(NULL), color_num(0)
{}


//governs robot behavior (direction and (new) state variables
void robotAlg::operator() (robot & curr){
	findNear(curr);
	if(pile_loc) managePiles(curr);
	setVars(curr);
	runBehavior(curr);
	sensorColor(curr);
}

//populate box_found and robot_found with pointers to nearbye objects
//also track pile sizes
void robotAlg::findNear(robot & curr){
	robot_found.clear();
	box_found.clear();
	//find nearbye boxes
	//clear temp sizes
	for(unsigned i=0;i<curr.piles.size();++i) curr.piles[i].temp=0;
	//find nearbye boxes in vector of all boxes and push pointers into found_boxes vector
	for(std::vector<box*>::iterator i=boxes->begin();i!=boxes->end();++i){
		if(!(*i)->taken() && distance(curr.loc,(*i)->loc)<curr.rad){
			//calculate numbers of each kind for pile size tracking
			if(pile_size){
				++curr.piles[(*i)->color_num].temp;
				//subtract unlike boxes if impurity counting enabled
				if(impurity_count){
					for(unsigned j=0;j<curr.piles.size();++j){
						if(j!=(*i)->color_num) --curr.piles[j].temp;
					}
				}
			}
			box_found.push_back(*i);
		}
	}
	//set max, loc, and good components of piles
	for(unsigned i=0;i<curr.piles.size();++i){
		curr.piles[i].max*=depreciation;
		curr.piles[i].update(curr.loc);
	}
	//find nearbye robots
	for(std::vector<robot*>::iterator i=robots->begin();i!=robots->end();++i){
		if(&curr!=*i){
			if(distance(curr.loc,(*i)->loc)<curr.rad){
				robot_found.push_back(*i);
			}
		}
	}}

//manage piles using selected control method
void robotAlg::managePiles(robot & curr){
	//check max value and location
	//shrink and disable pile if a pile turns out to be smaller than remembered
	for(unsigned i=0;i<curr.piles.size();++i){
		if(curr.piles[i].loc_good && curr.piles[i].temp<curr.piles[i].max
		&& distance(curr.loc,curr.piles[i].loc)<2){
			--curr.piles[i].max;
			curr.piles[i].loc_good=false;
		}
	}

	//code for robot control method
	switch(control_type){
	case 1: //shared tracking
		//check information from all nearby robots
		//copy if piles are good and larger
		for(unsigned i=0;i<robot_found.size();++i){
			for(unsigned j=0;j<color_num;++j){
				if(robot_found[i]->piles[j].loc_good && (robot_found[i]->piles[j].max > curr.piles[j].max || !curr.piles[j].loc_good)){
					if(distance(curr.loc,robot_found[i]->piles[j].loc)>curr.rad){
						curr.piles[j].setMax(robot_found[i]->piles[j]);
					}
				}
			}
		}
		break;
	case 2: //central tracking
		//use current pile information to update the pile vector
		//pile sizes now stored by algorthm, max values being copied back to robots
		for(unsigned i=0;i<color_num;++i){
			central_pile[i].max*=depreciation;
			if(curr.piles[i].temp>central_pile[i].max){
				central_pile[i].temp=curr.piles[i].temp;
				central_pile[i].update(curr.loc);
			}else if(!curr.piles[i].loc_good && distance(curr.piles[i].loc, central_pile[i].loc)<2){
				central_pile[i].loc_good=false;
				--central_pile[i].max;
			}else curr.piles[i].setMax(central_pile[i]);
		}
		break;
	}
}

//set variables pertaining to new knowledge
void robotAlg::setVars(robot & curr){
	//whether a box is visible by robot and its color
	if(!box_found.empty()){
		curr.box_vis.state_n=true;
		curr.box_vis.color_n=box_found.front()->color_num;
	}else{
		curr.box_vis.state_n=false;
		curr.box_vis.color_n=color_num;
	}
	//whether a robot is visible and its color
	if(!robot_found.empty()){
		curr.bot_vis.state_n=true;
		curr.bot_vis.color_n=robot_found.front()->has_box.color;
	}else{
		curr.bot_vis.state_n=false;
		curr.bot_vis.color_n=color_num;
	}
}

//call behavior functions based on robot knowledge
//affects direction variable and box pickup
void robotAlg::runBehavior(robot & curr){
	//first check against walls
	if(avoidWalls(curr)){
		//std::cout << "\tavoiding walls";
		return;
	}
	//check if ther is a bo to avoid
	if(curr.avoid_box!=NULL){
		if(distance(curr.loc,curr.avoid_box->loc)<2*curr.rad){
			//continue in same direction if moving until sufficiently far away
			//this prevents avoid wall and pile approach
			if(std::abs(curr.dir.x)<1 && std::abs(curr.dir.y)<1){			
				curr.dir=curr.loc-curr.avoid_box->loc;
				curr.dir.magnitude(2);
				//std::cout << "\tcontinuing";
			}
			//std::cout << "\tavoiding box";
			return;
		}
		curr.avoid_box=NULL;
	}
	//does not have box
	if(!curr.has_box.state){
		//check if near enough to pick up a box and act appropriately
		if(pick_up){
			for(unsigned box_loc=0; box_loc<box_found.size(); ++box_loc){
				if(!box_found[box_loc]->taken()){
					if(distance(curr.loc,box_found[box_loc]->loc)<15){
						if(pickUpPile(curr,box_loc) ){
							//std::cout << "\tpicking up box";
							pickUp(curr,box_loc);
							return;
						//set color so that it is no longer attracted to the box, occurs when pile is large
						}else{
							//std::cout << "\tnot picking up, changing color";
							curr.avoid_box=box_found[box_loc];
							return;
						}
					}
				}
			}
			//if no boxes are picked up, approach any that can be
			for(unsigned box_loc=0; box_loc<box_found.size(); ++box_loc){
				if(!box_found[box_loc]->taken()){
					//approach a box to pick it up
					//std::cout << "\tapproaching box to pick up";
					approach(curr,box_found[box_loc]->loc);
					return;
				}
			}
		}
		//secondary approach of box
		if(curr.bot_vis.state_n){
			if(secondary_box){
				unsigned bot_box_vis;
				if(secondaryBox(bot_box_vis)){
					//std::cout << "\tapproaching robot that sees box";
					approach(curr, robot_found[bot_box_vis]->loc);
					return;
				}
			}
			if(avoid_bot){
				avoidBot(curr);
				return;
			}
		}
	//code for robots tha have a box
	}else{
		unsigned same_index;
		//actions for seeing a box of the same color
		if(box_drop && visSameColorBox(curr, same_index)){
			if(distance(curr.loc,box_found[same_index]->loc)<10){
				if(!pile_size || dropPile(curr,1)){
					//std::cout << "\tdropping box";
					boxDrop(curr);
					return;
				} else if(!curr.piles[curr.has_box.color].loc_good){
					curr.avoid_box=box_found[same_index];
				}
			}
			if(!pile_size || dropPile(curr,1)){
				//std::cout << "\tapproaching box";
				approach(curr, box_found[same_index]->loc);
				return;
			}
		}
		//actions for seeing a robot that has a box of the same color
		if(visSameColor(curr, same_index)){
			if(robots_drop && distance(curr.loc,robot_found[same_index]->loc)<10){
				if(!pile_size || dropPile(curr,2)){
					//std::cout << "\tdropping box with other";
					boxDrop(curr);
					return;
				}
			}
			if(congregate_color && (!pile_size || dropPile(curr,2))){
				//std::cout << "\tapproaching robot";
				approach(curr, robot_found[same_index]->loc);
				return;
			}
		}
		//approach largest pile in memory
		if(pile_loc && approachMemPile(curr)){
			//std::cout << "\tapproaching largest pile";
			approach(curr,curr.piles[curr.has_box.color].loc);
			return;
		}
	}
	//if no algorithm applies act randomly
	if(random_dir){
			randomDir(curr);
			return;
	}
}

//set the color of the robot's sensor
void robotAlg::sensorColor(robot & curr){
	if(curr.has_box.state){
		curr.color_sensor_n=curr.has_box.color;
	}else if(curr.box_vis.state_n){
		curr.color_sensor_n=curr.box_vis.color_n;
	}else if(curr.bot_vis.state_n){
		curr.color_sensor_n=curr.box_vis.color_n;
	}else curr.color_sensor_n=color_num;
}

//knowledge helpers

//find any robots that see a box and move towards them
//returns index in robot_found vector
bool robotAlg::secondaryBox(unsigned & index){
	for(index=0;index<robot_found.size();++index){
		if(robot_found[index]->box_vis.state){
			return true;
		}
	}
	return false;
}

//used to move towards robots of same color
//will work if called on robots without boxes if necessary
//returns index in robot_found vector
bool robotAlg::visSameColor(robot const & curr, unsigned & index){
	for(index=0;index<robot_found.size();++index){
		if(robot_found[index]->has_box.color==curr.has_box.color){
			return true;
		}
	}
	return false;
}

//used to find boxes of the color that the robot has
//precondition: robot already has a box
//return index in box_found vector
bool robotAlg::visSameColorBox(robot const & curr, unsigned & index){
	for(index=0;index<box_found.size();++index){
		if(box_found[index]->color_num==curr.has_box.color){
			return true;
		}
	}
	return false;
}

/*

	actions

*/
//code to describe actions for each kind of behavior

//avoid walls if too near
bool robotAlg::avoidWalls(robot & curr){
	bool near_wall(false);
	if(curr.loc.x<=curr.rad+2 && curr.dir.x<0){
		curr.dir.x=1;
		near_wall=true;
	}else if(curr.loc.x>=width-curr.rad-2 && curr.dir.x>0){
		curr.dir.x=-1;
		near_wall=true;
	}
	if(curr.loc.y<=curr.rad+2 && curr.dir.y<0){
		curr.dir.y=1;
		near_wall=true;
	}else if(curr.loc.y>=height-curr.rad-2 && curr.dir.y>0){
		curr.dir.y=-1;
		near_wall=true;
	}
	if(near_wall) curr.dir.magnitude(2);
	return near_wall;
}

//pick up box at index
void robotAlg::pickUp(robot & curr, unsigned index){
	curr.curr_box=box_found[index]->pickUp();
	curr.has_box.state_n=true;
	curr.has_box.color_n=box_found[index]->color_num;
}

//drop the current box
void robotAlg::boxDrop(robot & curr){
	curr.avoid_box=curr.curr_box;
	curr.has_box.state_n=false;
	curr.has_box.color_n=color_num;
	curr.curr_box->drop(curr.loc);
}

//avoid robots
//assume that a robot is visible
//implemented to avoid first in vector
void robotAlg::avoidBot(robot & curr){
	robot & avoid=*robot_found.front();
	curr.dir=curr.loc-avoid.loc;
	curr.dir.magnitude(2);
}

//go in direction of a given point
void robotAlg::approach(robot & curr, pt loc){
	curr.dir=loc-curr.loc;
	curr.dir.magnitude(2);
}

//randomize dir
//adds random component to direction
void robotAlg::randomDir(robot & curr){
	curr.dir=randPt().magnitude(2)+6*curr.dir;
	curr.dir.magnitude(2);
}

//
//supporting logic functions
//

//checks whether robot can pick up box, regarding pile size
bool robotAlg::pickUpPile(robot & curr, unsigned index){
	return (curr.piles[box_found[index]->color_num].temp <
		curr.piles[box_found[index]->color_num].max)
		|| (curr.piles[box_found[index]->color_num].temp<3);
}

//checks whether the current pile is large enough to drop the box
bool robotAlg::dropPile(robot & curr, int shift){
	return curr.piles[curr.has_box.color].temp+shift >= curr.piles[curr.has_box.color].max;
}

//return whether a robot should approach a remembered pile
bool robotAlg::approachMemPile(robot & curr){
	return curr.piles[curr.has_box.color].loc_good;
}
