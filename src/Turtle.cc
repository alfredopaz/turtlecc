#include "Turtle.h"
#include <cmath>

using namespace cppTurtle;
static constexpr float PI = 3.14159265359f;

Turtle::Turtle(sf::RenderWindow &win)
: window(win), pos(win.getSize().x/2.f, win.getSize().y/2.f), heading(0.f), penIsDown(true), penColor(sf::Color::White), speed(1.f) {}

void Turtle::forward(float dist) {
  float rad = heading * PI / 180.f;
  sf::Vector2f newPos{pos.x + std::cos(rad) * dist,
                       pos.y + std::sin(rad) * dist};
  moveTo(newPos, penIsDown);
}

void Turtle::backward(float dist) { forward(-dist); }

void Turtle::right(float angle) { heading += angle; }

void Turtle::left(float angle) { heading -= angle; }

void Turtle::penUp() { penIsDown = false; }

void Turtle::penDown() { penIsDown = true; }

void Turtle::setColor(const sf::Color &color) { penColor = color; }

void Turtle::setColor(uint8_t r, uint8_t g, uint8_t b) { penColor = sf::Color(r, g, b); }

void Turtle::goTo(float x, float y) { moveTo({x, y}, penIsDown); }

void Turtle::setSpeed(float s) { speed = s; }

void Turtle::circle(float radius) {
  const int steps = 36;
  float stepAngle = 360.f / steps;
  for (int i = 0; i < steps; ++i) {
    right(stepAngle);
    forward(2 * PI * radius / steps);
  }
}

void Turtle::clear() { lines.clear(); }

void Turtle::home() {
  pos = {window.getSize().x/2.f, window.getSize().y/2.f};
  heading = 0.f;
}

void Turtle::draw() {
  if (!lines.empty())
    window.draw(&lines[0], lines.size(), sf::Lines);
}

void Turtle::moveTo(const sf::Vector2f &newPos, bool drawLine) {
  if (drawLine) {
    lines.emplace_back(pos, penColor);
    lines.emplace_back(newPos, penColor);
  }
  pos = newPos;
}
