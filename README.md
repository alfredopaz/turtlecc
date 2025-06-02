# cppTurtle

**Biblioteca en C++ que emula la API de `turtle.py` usando SFML, con soporte para colores RGB, ejecución mediante callback y creación de objetos Turtle vía factory.**

---

## Descripción

cppTurtle ofrece:

- Clase `Turtle`: comandos de dibujo (p.ej. `forward()`, `left()`, `penUp()`, etc.).
- Función `run`: oculta la gestión de ventana y eventos, recibe un callback de dibujo.
- Clase `Application`: factory para crear tu ventana y objeto `Turtle`, con método `run()` para lanzar el bucle.
- `setColor(r, g, b)`: sobrecarga para configurar colores mediante valores RGB.

Así puedes escoger entre un modelo pasivo (callback) o uno activo (crear y controlar tu turtle).  

---

## Requisitos

- **SFML 2.5** (o superior)
  - Ubuntu/Debian: `sudo apt-get install libsfml-dev`
  - macOS (Homebrew): `brew install sfml`
- **Compilador C++11**
- **Make**

---

## Estructura del proyecto

```text
cppTurtle/
├── Makefile
├── include/
│   └── Turtle.h
├── src/
│   ├── Turtle.cc
│   └── App.cc
└── examples/
    ├── main_callback.cc
    ├── main_object.cc
    └── main_fractal.cc
```

---

## Compilación y ejecución

```bash
cd cppTurtle
make                 # Compila la biblioteca y los ejemplos
./turtle_example_cb  # Ejecuta ejemplo run(callback)
./turtle_example_obj # Ejecuta ejemplo Application
./turtle_example_fractal # Ejecuta fractal
make clean           # Limpia artefactos
```

---

## API principal

### Clase `cppTurtle::Turtle`

```cpp
Turtle(sf::RenderWindow &window);
void forward(float dist);
void backward(float dist);
void left(float angle);
void right(float angle);
void penUp();
void penDown();
void setColor(const sf::Color &color);
void setColor(uint8_t r, uint8_t g, uint8_t b);
void goTo(float x, float y);
void setSpeed(float speed);
void circle(float radius);
void clear();
void home();
void draw();
```

### Función `run` (modo callback)

```cpp
void run(
  std::function<void(Turtle&)> drawFunc,
  unsigned int width = 800,
  unsigned int height = 600,
  const std::string &title = "cppTurtle Demo"
);
```

### Clase `cppTurtle::Application` (modo objeto)

```cpp
class Application {
public:
  Application(
    unsigned int width = 800,
    unsigned int height = 600,
    const std::string &title = "cppTurtle App"
  );
  Turtle& turtle();
  void run();
private:
  sf::RenderWindow window;
  Turtle t;
};
```
