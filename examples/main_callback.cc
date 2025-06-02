#include <functional>
#include "Turtle.h"

void draw(cppTurtle::Turtle &t) {
  t.setColor(255, 165, 0);
  t.setSpeed(2.f);
  for (int i = 0; i < 6; ++i) {
    t.forward(100);
    t.right(60);
  }
}

int main() {
  cppTurtle::run(draw, 800, 600, "Callback Demo");
  return 0;
}
