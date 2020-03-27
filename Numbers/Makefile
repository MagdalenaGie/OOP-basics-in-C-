CXX = g++

CXXFLAGS = -std=c++11 -Wall -pedantic

SOURCES = $(wildcard *.cpp)

OBJS = $(SOURCES:.cpp=.o)

EXEC = main



all: $(EXEC) run



$(EXEC): $(OBJS)

	$(CXX) $^ -o $@



%.o: %.cpp %.h

	$(CXX) $(CXXFLAGS) -c $<



%.o: %.cpp

	$(CXX) $(CXXFLAGS) -c $<



clean:

	rm -rf *.o $(EXEC)



run:

	./$(EXEC)



check: 

	valgrind ./$(EXEC)



.PHONY: all clean run check
