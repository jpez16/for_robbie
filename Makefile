CXX = g++-5 -std=c++14
CXXFLAGS = -Wall -O -g -MMD # use -MMD to generate dependencies
LIBFLAGS = -ljsoncpp # link in boost's date and time library and JSON cpp 
SOURCES = $(wildcard *.cpp)  # list of all .cpp files in the current directory
OBJECTS = $(SOURCES:.cpp=.o) # .o files depend upon .cpp files with same names
DEPENDS = ${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cpp file
EXEC=blessed

# First target in the makefile is the default target.
# Note that the LIBFLAGS must come last in the command
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)  $(LIBFLAGS)

%.o: %.cpp 
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBFLAGS)

-include ${DEPENDS}

.PHONY: clean
clean:
	rm  -f $(OBJECTS) $(DEPENDS) $(EXEC)
