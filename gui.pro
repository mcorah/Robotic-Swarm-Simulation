HEADERS =gui.h swarm_world.h includes.h robot.h robotAlg.h box.h point.h
SOURCES =gui.cpp main.cpp swarm_world.cpp robot.cpp robotAlg.cpp box.cpp point.cpp
FORMS =swarm_gui.ui

#install
target.path=swarm_sim
sources.files=$$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path=.
INSTALLS += target sources
