// TestLine.cc
#include "Turtle.h"

int main() {
    // Crea la ventana y la tortuga
    cppTurtle::Application app(400, 200, "Test Line");
    auto &t = app.turtle();

    // Levantamos el lápiz y movemos antes de dibujar
    t.penUp();
    t.goTo(50, 100);
    t.penDown();

    // Dibuja una línea de 300px
    t.setColor(255, 100, 0);  // naranja suave
    t.setSpeed(5.0f);
    t.forward(300.0f);

    // Ejecuta el bucle de ventana (permanece abierta hasta cerrarla)
    app.run();
    return 0;
}
