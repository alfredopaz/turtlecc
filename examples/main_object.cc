#include "Turtle.h"

int main() {
  cppTurtle::Application app(800, 600, "Object Demo");
  auto &t = app.turtle();
  t.setColor(0, 255, 127);
  t.setSpeed(2.f);
  t.circle(80);
  app.run();
  return 0;
}
