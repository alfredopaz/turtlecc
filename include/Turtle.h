#ifndef CPP_TURTLE_H
#define CPP_TURTLE_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <string>

namespace cppTurtle {

class Turtle {
public:
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

private:
  sf::RenderWindow &window;
  sf::Vector2f pos;
  float heading;
  bool penIsDown;
  sf::Color penColor;
  float speed;
  std::vector<sf::Vertex> lines;
  void moveTo(const sf::Vector2f &newPos, bool drawLine);
};

// Modo callback
void run(
  std::function<void(Turtle&)> drawFunc,
  unsigned int width = 800,
  unsigned int height = 600,
  const std::string &title = "cppTurtle Demo"
);

// Modo objeto
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

} // namespace cppTurtle

#endif // CPP_TURTLE_H
