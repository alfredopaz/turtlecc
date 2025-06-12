#include "Turtle.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>

using namespace cppTurtle;
static constexpr float PI = 3.14159265359f;

Turtle::Turtle(sf::RenderWindow &win)
: window(win),
  pos(win.getSize().x/2.f, win.getSize().y/2.f),
  heading(0.f),
  penIsDown(true),
  penColor(sf::Color::White),
  speed(1.f)
{
  // Inicializar forma de la tortuga (triángulo)
  shape.setPointCount(3);
  shape.setPoint(0, sf::Vector2f( 0.f, -5.f));
  shape.setPoint(1, sf::Vector2f(10.f,  0.f));
  shape.setPoint(2, sf::Vector2f( 0.f,  5.f));
  shape.setFillColor(sf::Color::Green);
  shape.setPosition(pos);
  shape.setRotation(heading);
}

void Turtle::forward(float dist) {
  float rad = heading * PI / 180.f;
  sf::Vector2f newPos {
    pos.x + static_cast<float>(::cos(rad) * dist),
    pos.y + static_cast<float>(::sin(rad) * dist)
  };
  moveTo(newPos, penIsDown);
  updateDisplay();
}

void Turtle::backward(float dist) {
  forward(-dist);
}

void Turtle::right(float angle) {
  heading += angle;
  shape.setRotation(heading);
  updateDisplay();
}

void Turtle::left(float angle) {
  heading -= angle;
  shape.setRotation(heading);
  updateDisplay();
}

void Turtle::penUp() {
  penIsDown = false;
}

void Turtle::penDown() {
  penIsDown = true;
}

void Turtle::setColor(const sf::Color &color) {
  penColor = color;
  shape.setFillColor(color);
  updateDisplay();
}

void Turtle::setColor(uint8_t r, uint8_t g, uint8_t b) {
  penColor = sf::Color(r, g, b);
  shape.setFillColor(penColor);
  updateDisplay();
}

void Turtle::goTo(float x, float y) {
  moveTo({x, y}, penIsDown);
  shape.setPosition(pos);
  updateDisplay();
}

void Turtle::setSpeed(float s) {
  speed = s;
}

void Turtle::circle(float radius) {
  const int steps = 36;
  float stepAngle = 360.f / steps;
  for (int i = 0; i < steps && window.isOpen(); ++i) {
    right(stepAngle);
    forward(static_cast<float>(2 * PI * radius / steps));
    // updateDisplay inside forward/right handles sleep and events
  }
}

void Turtle::clear() {
  lines.clear();
  updateDisplay();
}

void Turtle::home() {
  pos = { window.getSize().x/2.f, window.getSize().y/2.f };
  heading = 0.f;
  shape.setPosition(pos);
  shape.setRotation(heading);
  updateDisplay();
}

void Turtle::draw() {
  // Las líneas ya se dibujan en updateDisplay; aquí solo si se necesita
  if (!lines.empty()) {
    window.draw(&lines[0], lines.size(), sf::Lines);
  }
}

void Turtle::moveTo(const sf::Vector2f &newPos, bool drawLine) {
  if (drawLine) {
    lines.emplace_back(pos, penColor);
    lines.emplace_back(newPos, penColor);
  }
  pos = newPos;
  shape.setPosition(pos);
}

void Turtle::updateDisplay() {
  // Procesar eventos para mantener la ventana responsiva
  sf::Event e;
  while (window.pollEvent(e)) {
    if (e.type == sf::Event::Closed) {
      window.close();
      return;
    }
  }

  window.clear(sf::Color::Black);
  if (!lines.empty()) {
    window.draw(&lines[0], lines.size(), sf::Lines);
  }
  window.draw(shape);
  window.display();

  sf::sleep(sf::milliseconds(static_cast<sf::Int32>(100 / speed)));
}
