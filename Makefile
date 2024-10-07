CXX = g++	
CPPFILES := $(wildcard ./*.cpp) \
			$(wildcard ./Rating/*.cpp) \
			$(wildcard ./User/*.cpp) \
			$(wildcard ./System/*.cpp) \
			$(wildcard ./Request/*.cpp) \
			$(wildcard ./Functions/*.cpp) \
			$(wildcard ./Motorbike/*.cpp)
# OFILES := $(patsubst %.cpp, ./build/%.o, $(notdir $(CPPFILES)))


all: clean ./build/main.exe run

# Compile source files to object files

./build/main.exe:	
	$(CXX) $(CPPFILES) -o ./build/main 

run: ./build/main.exe
	./build/main.exe

clean:
	del .\build\main.exe

