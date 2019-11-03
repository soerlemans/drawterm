CXXFLAGS = -std=c++17 -O2 -c -Wall -Wextra -Wno-narrowing #--help=optimizers
LIBS = -lncurses -ltinfo

OBJECTS =\
	CursorAttributes.o Cursor.o Except.o Frame.o InitExcept.o LogicExcept.o main.o MovementHandle.o NcursesOptions.o Prompt.o ScreenHandle.o Video.o 
VPATH = src

drawterm : $(OBJECTS)
	g++ -O2 -o $@ $^ $(LIBS)

CursorAttributes.o: CursorAttributes.cpp CursorAttributes.hpp Cursor.hpp
	g++ $(CXXFLAGS) $<

Cursor.o: Cursor.cpp Cursor.hpp
	g++ $(CXXFLAGS) $<

Except.o: Except.cpp Except.hpp
	g++ $(CXXFLAGS) $<

Frame.o: Frame.cpp Frame.hpp CursorAttributes.hpp Cursor.hpp \
 NcursesOptions.hpp InitExcept.hpp Except.hpp LogicExcept.hpp
	g++ $(CXXFLAGS) $<

InitExcept.o: InitExcept.cpp InitExcept.hpp Except.hpp
	g++ $(CXXFLAGS) $<

LogicExcept.o: LogicExcept.cpp LogicExcept.hpp Except.hpp
	g++ $(CXXFLAGS) $<

main.o: main.cpp MovementHandle.hpp Cursor.hpp ScreenHandle.hpp \
 Prompt.hpp Video.hpp Frame.hpp CursorAttributes.hpp NcursesOptions.hpp \
 InitExcept.hpp Except.hpp LogicExcept.hpp
	g++ $(CXXFLAGS) $<

MovementHandle.o: MovementHandle.cpp MovementHandle.hpp Cursor.hpp
	g++ $(CXXFLAGS) $<

NcursesOptions.o: NcursesOptions.cpp NcursesOptions.hpp InitExcept.hpp \
 Except.hpp
	g++ $(CXXFLAGS) $<

Prompt.o: Prompt.cpp Prompt.hpp Video.hpp Frame.hpp CursorAttributes.hpp \
 Cursor.hpp NcursesOptions.hpp InitExcept.hpp Except.hpp LogicExcept.hpp
	g++ $(CXXFLAGS) $<

ScreenHandle.o: ScreenHandle.cpp ScreenHandle.hpp Prompt.hpp Video.hpp \
 Frame.hpp CursorAttributes.hpp Cursor.hpp NcursesOptions.hpp \
 InitExcept.hpp Except.hpp LogicExcept.hpp
	g++ $(CXXFLAGS) $<

Video.o: Video.cpp Video.hpp Frame.hpp CursorAttributes.hpp Cursor.hpp \
 NcursesOptions.hpp InitExcept.hpp Except.hpp LogicExcept.hpp
	g++ $(CXXFLAGS) $<

clean :  #remove all the executable and all the object files
	rm drawterm $(wildcard *.o)

.PHONY: clean

