#include "Turtle.h"

void drawTree(cppTurtle::Turtle &t, float length, int depth) {
  if (depth == 0) return;
  t.forward(length);
  t.left(30);
  drawTree(t, length * 0.6f, depth - 1);
  t.right(60);
  drawTree(t, length * 0.6f, depth - 1);
  t.left(30);
  t.backward(length);
}

int main() {
  cppTurtle::Application app(800, 600, "Árbol Fractal");
  auto &t = app.turtle();
  t.setColor(34, 139, 34);
  t.penUp(); t.goTo(400, 550); t.penDown();
  drawTree(t, 120.0f, 6);
  app.run();
  return 0;
}
