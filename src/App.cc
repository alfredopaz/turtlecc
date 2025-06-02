#include "Turtle.h"
#include <SFML/Graphics.hpp>

namespace cppTurtle {

void run(std::function<void(Turtle&)> drawFunc,
         unsigned int width, unsigned int height,
         const std::string &title) {
  sf::RenderWindow window(sf::VideoMode(width, height), title);
  Turtle t(window);
  drawFunc(t);
  while (window.isOpen()) {
    sf::Event e;
    while (window.pollEvent(e)) {
      if (e.type == sf::Event::Closed) window.close();
    }
    window.clear(sf::Color::Black);
    t.draw();
    window.display();
  }
}

Application::Application(unsigned int width, unsigned int height,
                         const std::string &title)
  : window(sf::VideoMode(width, height), title), t(window) {}

Turtle& Application::turtle() { return t; }

void Application::run() {
  while (window.isOpen()) {
    sf::Event e;
    while (window.pollEvent(e)) {
      if (e.type == sf::Event::Closed) window.close();
    }
    window.clear(sf::Color::Black);
    t.draw();
    window.display();
  }
}

} // namespace cppTurtle
