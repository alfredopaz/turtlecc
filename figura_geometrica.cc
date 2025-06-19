#include "Turtle.h"

#include <iostream>

void dibujarPoligono(cppTurtle::Turtle &t, int n, float lado); 

int main() {
   
    cppTurtle::Application app(600, 800, "Poligono");
    auto &t = app.turtle();

    int n;
    std::cout << "Ingrese el numero de lados: ";
    std::cin >> n;

    
    t.penUp();
    t.goTo(200, 400); 
    t.penDown();
    t.setColor(0, 150, 255); // Azul claro
    t.setSpeed(5.0f);


    dibujarPoligono(t, n, 50.0f); // Longitud de lado 50

    
    app.run();
    return 0;
}
 void dibujarPoligono(cppTurtle::Turtle &t, int n, float lado) { 
   if (n < 3) return; 

  float angulo = 360.0f / n;

    for (int i = 0; i < n; ++i) {
      t.forward(100);
      t.left(angulo);
    }   
}  
