CONFIG += release
INCLUDEPATH = ./include
HEADERS = include/gui.h include/swarm_world.h include/swarm_includes.h include/robot.h include/robotAlg.h include/box.h include/point.h include/knowledgeItem.h
SOURCES = src/gui.cpp src/main.cpp src/swarm_world.cpp src/robot.cpp src/robotAlg.cpp src/box.cpp src/point.cpp
FORMS = swarm_gui.ui
OBJECTS_DIR = ./temp

#install
target.path=swarm_sim
sources.files=$$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path=./src
INSTALLS += target sources
