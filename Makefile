CXX = g++
CPPFLAGS = -Iinclude
CXXFLAGS = -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC = src/Turtle.cc src/App.cc
OBJ = $(SRC:.cc=.o)
LIB = libcppTurtle.a

all: example_cb example_obj example_fractal

lib: $(OBJ)
	ar rcs $(LIB) $(OBJ)

example_cb: lib examples/main_callback.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o turtle_example_cb examples/main_callback.cc $(LIB) $(LDFLAGS)

example_obj: lib examples/main_object.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o turtle_example_obj examples/main_object.cc $(LIB) $(LDFLAGS)

example_fractal: lib examples/main_fractal.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o turtle_example_fractal examples/main_fractal.cc $(LIB) $(LDFLAGS)

clean:
	rm -f src/*.o $(LIB) turtle_example_cb turtle_example_obj turtle_example_fractal
