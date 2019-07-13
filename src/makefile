CXXFLAGS = -std=c++17 -O2 -c -Wall -Wextra -Wno-narrowing #--help=optimizers shows optimizations
LIBS = -lncurses

OBJECTS = main.o MovementHandle.o Cursor.o ScreenHandle.o \
	  Prompt.o NcursesOptions.o InitExcept.o LogicExcept.o Except.o Video.o Frame.o
VPATH=src

#.SECONDEXPANSION:
#OB = *.o
#OBJECTS = $$(OB)

#some thing is wrong with m_video object that does not exist anymore
#-rules--

drawterm : $(OBJECTS)
	 g++ -O2 -o $@ $^ $(LIBS)

main.o : main.cpp MovementHandle.o ScreenHandle.o
	g++ $(CXXFLAGS) $<

MovementHandle.o : MovementHandle.cpp MovementHandle.hpp Cursor.o
	g++ $(CXXFLAGS) $<

Cursor.o : Cursor.cpp Cursor.hpp
	g++ $(CXXFLAGS) $<

ScreenHandle.o : ScreenHandle.cpp ScreenHandle.hpp Prompt.o
	g++ $(CXXFLAGS) $<

Prompt.o : Prompt.cpp Prompt.hpp Cursor.o NcursesOptions.o
	g++ $(CXXFLAGS) $<

NcursesOptions.o : NcursesOptions.cpp NcursesOptions.hpp InitExcept.o
	g++ $(CXXFLAGS) $<

InitExcept.o : InitExcept.cpp InitExcept.hpp Except.o
	g++ $(CXXFLAGS) $<

LogicExcept.o : LogicExcept.cpp LogicExcept.hpp Except.o
	g++ $(CXXFLAGS) $<

Except.o : Except.cpp Except.hpp 
	g++ $(CXXFLAGS) $<

Video.o : Video.cpp Video.hpp Frame.o
	g++ $(CXXFLAGS) $<

Frame.o : Frame.cpp Frame.hpp LogicExcept.o Cursor.o
	g++ $(CXXFLAGS) $<

.PHONY: install uninstall clean

install : #install the exceutable on the system

uninstall : #uninstall the executable on the system

clean :  #remove all the executable and all the object files
	rm drawterm $(wildcard *.o)


