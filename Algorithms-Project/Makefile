CXX=g++
CXXFLAGS= -std=c++11 -g -Wall


PROGRAM_CREATE = create
PROGRAM_BRUTEFORCE = bruteforce
PROGRAM_DIVIDECONQUER = divideconquer

.PHONY: all
all: $(PROGRAM_CREATE) $(PROGRAM_BRUTEFORCE) $(PROGRAM_DIVIDECONQUER)

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o  $(PROGRAM_CREATE) $(PROGRAM_BRUTEFORCE) $(PROGRAM_DIVIDECONQUER) 


.PHONY: clean-all
clean-all: clean
	rm -rf $(PROGRAM_CREATE)

$(PROGRAM_CREATE):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_CREATE)  create.cpp

$(PROGRAM_BRUTEFORCE):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_BRUTEFORCE)  bruteforce.cpp

$(PROGRAM_DIVIDECONQUER):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_DIVIDECONQUER)  divideconquer.cpp
