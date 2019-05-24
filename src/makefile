CXXFLAGS = -std=c++17 -c -Wall
LIBS = -lncurses

OBJECTS = main.o MovementHandle.o Cursor.o ScreenHandle.o \
	  Prompt.o NcursesOptions.o RT_Error.o Video.o Frame.o RGB.o

#-rules--

drawterm : $(OBJECTS)
	g++ -o $@ $(OBJECTS) $(LIBS)

main.o : main.cpp MovementHandle.o ScreenHandle.o
	g++ $(CXXFLAGS) main.cpp

MovementHandle.o : MovementHandle.cpp MovementHandle.hpp Cursor.o
	g++ $(CXXFLAGS) MovementHandle.cpp

Cursor.o : Cursor.cpp Cursor.hpp RGB.o
	g++ $(CXXFLAGS) Cursor.cpp

ScreenHandle.o : ScreenHandle.cpp ScreenHandle.hpp Prompt.o Video.o
	g++ $(CXXFLAGS) ScreenHandle.cpp 

Prompt.o : Prompt.cpp Prompt.hpp Cursor.o NcursesOptions.o
	g++ $(CXXFLAGS) Prompt.cpp 

NcursesOptions.o : NcursesOptions.cpp NcursesOptions.hpp RT_Error.o
	g++ $(CXXFLAGS) NcursesOptions.cpp 

RT_Error.o : RT_Error.cpp RT_Error.hpp 
	g++ $(CXXFLAGS) RT_Error.cpp

Video.o : Video.cpp Video.hpp Frame.o
	g++ $(CXXFLAGS) Video.cpp 

Frame.o : Frame.cpp Frame.hpp Cursor.o
	g++ $(CXXFLAGS) Frame.cpp 

RGB.o : RGB.cpp RGB.hpp 
	g++ $(CXXFLAGS) RGB.cpp

clean :
	rm drawterm $(OBJECTS)


