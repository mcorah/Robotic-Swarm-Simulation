#############################################################################
# Makefile for building: gui
# Generated by qmake (2.01a) (Qt 4.7.4) on: Thu May 10 01:52:37 2012
# Project:  gui.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile gui.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = gui.cpp \
		main.cpp \
		swarm_world.cpp \
		robot.cpp \
		robotAlg.cpp \
		box.cpp \
		point.cpp moc_gui.cpp
OBJECTS       = gui.o \
		main.o \
		swarm_world.o \
		robot.o \
		robotAlg.o \
		box.o \
		point.o \
		moc_gui.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		gui.pro
QMAKE_TARGET  = gui
DESTDIR       = 
TARGET        = gui

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_swarm_gui.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: gui.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile gui.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile gui.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/gui1.0.0 || $(MKDIR) .tmp/gui1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/gui1.0.0/ && $(COPY_FILE) --parents gui.h swarm_world.h includes.h robot.h robotAlg.h box.h point.h .tmp/gui1.0.0/ && $(COPY_FILE) --parents gui.cpp main.cpp swarm_world.cpp robot.cpp robotAlg.cpp box.cpp point.cpp .tmp/gui1.0.0/ && $(COPY_FILE) --parents swarm_gui.ui .tmp/gui1.0.0/ && (cd `dirname .tmp/gui1.0.0` && $(TAR) gui1.0.0.tar gui1.0.0 && $(COMPRESS) gui1.0.0.tar) && $(MOVE) `dirname .tmp/gui1.0.0`/gui1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/gui1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_gui.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_gui.cpp
moc_gui.cpp: includes.h \
		ui_swarm_gui.h \
		swarm_world.h \
		robot.h \
		knowledgeItem.h \
		pileInfo.h \
		point.h \
		box.h \
		robotAlg.h \
		gui.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gui.h -o moc_gui.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_swarm_gui.h
compiler_uic_clean:
	-$(DEL_FILE) ui_swarm_gui.h
ui_swarm_gui.h: swarm_gui.ui
	/usr/bin/uic-qt4 swarm_gui.ui -o ui_swarm_gui.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

gui.o: gui.cpp includes.h \
		gui.h \
		ui_swarm_gui.h \
		swarm_world.h \
		robot.h \
		knowledgeItem.h \
		pileInfo.h \
		point.h \
		box.h \
		robotAlg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gui.o gui.cpp

main.o: main.cpp includes.h \
		gui.h \
		ui_swarm_gui.h \
		swarm_world.h \
		robot.h \
		knowledgeItem.h \
		pileInfo.h \
		point.h \
		box.h \
		robotAlg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

swarm_world.o: swarm_world.cpp includes.h \
		swarm_world.h \
		robot.h \
		knowledgeItem.h \
		pileInfo.h \
		point.h \
		box.h \
		robotAlg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o swarm_world.o swarm_world.cpp

robot.o: robot.cpp includes.h \
		robot.h \
		knowledgeItem.h \
		pileInfo.h \
		point.h \
		box.h \
		robotAlg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o robot.o robot.cpp

robotAlg.o: robotAlg.cpp includes.h \
		robot.h \
		knowledgeItem.h \
		pileInfo.h \
		point.h \
		box.h \
		robotAlg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o robotAlg.o robotAlg.cpp

box.o: box.cpp includes.h \
		box.h \
		point.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o box.o box.cpp

point.o: point.cpp includes.h \
		point.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o point.o point.cpp

moc_gui.o: moc_gui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gui.o moc_gui.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/gui/ || $(MKDIR) $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/gui/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/gui/$(QMAKE_TARGET)"
	-$(STRIP) "$(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/gui/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/gui/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/gui/ 


install_sources: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./ || $(MKDIR) $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./ 
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/gui.cpp $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/main.cpp $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/swarm_world.cpp $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/robot.cpp $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/robotAlg.cpp $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/box.cpp $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/point.cpp $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/gui.h $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/swarm_world.h $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/includes.h $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/robot.h $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/robotAlg.h $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/box.h $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/point.h $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/swarm_gui.ui $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./
	-$(INSTALL_FILE) /home/micah/Robotic-Swarm-Simulation/gui.pro $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./


uninstall_sources:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./gui.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./main.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./swarm_world.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./robot.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./robotAlg.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./box.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./point.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./gui.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./swarm_world.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./includes.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./robot.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./robotAlg.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./box.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./point.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./swarm_gui.ui 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./gui.pro
	-$(DEL_DIR) $(INSTALL_ROOT)/home/micah/Robotic-Swarm-Simulation/./ 


install:  install_target install_sources  FORCE

uninstall: uninstall_target uninstall_sources   FORCE

FORCE:

