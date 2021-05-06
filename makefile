CXX= g++
CXXFLAGS= -w -g -std=c++1y
THREADFLAGS= # -lpthread

EXE_NAME=test

SRC = $(wildcard *.cpp)
OBJ = $(addsuffix .o, $(basename $(SRC)))

REBUILDABLES=$(OBJ) $(EXE_NAME)

all: ${EXE_NAME}

#  $@ target name, $^ target deps, $< matched pattern
$(EXE_NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(THREADFLAGS)
	@echo "Built $@ successfully" 

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	-rm -f $(REBUILDABLES)
