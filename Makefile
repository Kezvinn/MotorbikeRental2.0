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

#--------------------------------------------------------------------------------------------------------------
# different ver of make file
# # CPPFILES := $(wildcard **/*.cpp)	# all .cpp file
# CPPFILES := $(wildcard *.cpp) \
# 			$(wildcard ./Function/*.cpp) \
# 			$(wildcard ./Motorbike/*.cpp) \
# 			$(wildcard ./Request/*.cpp)	\
# 			$(wildcard ./Review/*.cpp)	\
# 			$(wildcard ./System/*.cpp)	\
# 			$(wildcard ./User/*.cpp)
# OFILES := $(addprefix Build/, $(notdir $(CPPFILES:.cpp=.o)))	# all .o file (expecting)

# OBJFILES := $(wildcard ./Build/*.o)	# all .o file (real)

# CXX = g++
# CXXFLAGS = -g -Wall

# all: clean run

# Build/%.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# run: $(OFILES)
# 	$(CXX) $(CXXFLAGS) $(OFILES) -o ./Build/main.exe
# 	./Build/main.exe
# clean:
# 	del .\Build\*.o
# 	del .\Build\main.exe
#--------------------------------------------------------------------------------------------------------------


# CXX = g++
# CXXFLAGS = -g -Wall
# # CPPFILES := $(wildcard ./*.cpp)
# # OFILES = $(CFILES: ./%.cpp = ./Build/%.o)
# OBJFILES = $(wildcard ./Build/*.o)

# all: clean run

# ./Build/*.o: ./Review/*.cpp ./User/*.cpp ./System/*.cpp ./Request/*.cpp ./Functions/*.cpp ./Motorbike/*.cpp

# # review
# 	$(CXX) $(CXXFLAGS) -c ./review/review.cpp -o ./Build/review.o
# 	$(CXX) $(CXXFLAGS) -c ./review/bike_Review.cpp -o ./Build/bike_review.o
# 	$(CXX) $(CXXFLAGS) -c ./review/member_Review.cpp -o ./Build/mem_review.o

# # user
# 	$(CXX) $(CXXFLAGS) -c ./User/user.cpp -o ./Build/user.o
# 	$(CXX) $(CXXFLAGS) -c ./User/admin.cpp -o ./Build/admin.o
# 	$(CXX) $(CXXFLAGS) -c ./User/member.cpp -o ./Build/member.o

# # system
# 	$(CXX) $(CXXFLAGS) -c ./System/System.cpp -o ./Build/System.o

# # request
# 	$(CXX) $(CXXFLAGS) -c ./Request/Request.cpp -o ./Build/Request.o

# # function
# 	$(CXX) $(CXXFLAGS) -c ./Functions/my_func.cpp -o ./Build/my_func.o

# # bike
# 	$(CXX) $(CXXFLAGS) -c ./Motorbike/Motorbike.cpp -o ./Build/Motorbike.o

# # main
# 	$(CXX) $(CXXFLAGS) -c main.cpp -o ./Build/main.o
# run: ./Build/*.o
# 	$(CXX) -ld $(CXXFLAGS) -c $(OBJFILES) -o ./Build/main.exe
# 	./Build/main.exe
# clean:
# 	del .\Build\*.o
# 	del .\Build\main.exe
#--------------------------------------------------------------------------------------------------------------