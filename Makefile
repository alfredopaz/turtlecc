CXX = g++
CPPFLAGS = -Iinclude
CXXFLAGS = -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files for the library
LIB_SRCS = src/Turtle.cc src/App.cc
LIB_OBJS = $(LIB_SRCS:.cc=.o)
LIB      = libcppTurtle.a

# Default target: build the library
all: $(LIB)

# Archive library objects into a static library
$(LIB): $(LIB_OBJS)
	@echo "  AR    $@"
	ar rcs $@ $^

# Compile .cc -> .o for src directory
src/%.o: src/%.cc
	@echo "  CXX   $@"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Generic rule: compile any .cc in the project root into an executable
# Usage: make MyProgram  (requires MyProgram.cc present in the root)
%: %.cc $(LIB)
	@echo "  CXX   $@"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LIB) $(LDFLAGS)

# Clean up objects, library, and executables corresponding to root .cc files
clean:
	@echo "  CLEANING..."
	rm -f $(LIB_OBJS) $(LIB) $(patsubst %.cc,%,$(wildcard *.cc))
