CXX = g++	
CXXFLAGS = -g -Wall
CPPFILES = $(shell dir /s /b *.cpp)

# OFILES := $(patsubst %.cpp, ./build/%.o, $(notdir $(CPPFILES)))

all: clean run

# Compile source files to object files
./build/main.exe:	
	$(CXX) $(CXXFLAGS) $(CPPFILES) -o ./build/main

run: ./build/main.exe
	./build/main.exe

clean:
	del .\build\main.exe
