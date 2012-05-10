/*
Robotic Swarm Simulation, Developed by Micah Corah
*/

//trivial main that starts the gui
#include "includes.h"
#include "gui.h"

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	swarm_gui *interface = new swarm_gui;
	interface->show();
	return app.exec();
}
