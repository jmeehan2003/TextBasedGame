
PROGRAM = outlaw
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g


SOURCES = $(wildcard *.cpp)
# Person.cpp Student.cpp Instructor.cpp University.cpp Menu.cpp Building.cpp mainUni.cpp

OBJECTS = $(SOURCES:.cpp=.o)
# Person.o Student.o Instructor.o University.o Menu.o Building.o mainUni.o

HEADERS = $(wildcard *.hpp) 

default: ${OBJECTS} 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${PROGRAM} 

clean:
	rm -f ${OBJECTS} ${PROGRAM}

