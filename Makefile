# Makefile que permite:  make APP=MiPrograma

# 1) Compilador y flags
CXX       = g++
CPPFLAGS  = -Iinclude
CXXFLAGS  = -std=c++11
LDFLAGS   = -lsfml-graphics -lsfml-window -lsfml-system

# 2) Biblioteca estática (Turtle + App)
LIB_SRCS  = src/Turtle.cc src/App.cc
LIB_OBJS  = $(LIB_SRCS:.cc=.o)
LIB       = libcppTurtle.a

# 3) Programa a compilar
ifndef APP
  $(error Debes indicar APP, p.ej.  make APP=MiPrograma)
endif
SRC = $(APP).cc

.PHONY: all lib clean

# 4) Target por defecto: compila la biblioteca y luego tu APP
all: lib $(APP)

# 5) Construir la biblioteca
lib: $(LIB)

$(LIB): $(LIB_OBJS)
	@echo "  AR    $@"
	ar rcs $@ $^

# 6) Regla implícita: .cc → .o
#    (si tu Make no la tiene, descomenta estas líneas)
#%.o: %.cc
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# 7) Compilar tu APP: APP.cc → ejecutable APP
$(APP): $(SRC) $(LIB)
	@echo "  CXX   $@"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LIB) $(LDFLAGS)

# 8) Limpiar objetos, librería y tu ejecutable
clean:
	@echo "  CLEANING..."
	rm -f $(LIB_OBJS) $(LIB) $(APP)
