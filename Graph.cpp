#include "Graph.h"
#include <iostream>
#include <cmath>

Graph::Graph(sf::RenderWindow& win) : window(win), xMin(-10), xMax(10), yMin(-10), yMax(10) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
    }
}

void Graph::addFunction(std::shared_ptr<Function> func) {
    functions.push_back(func);
}

void Graph::clearFunctions() {
    functions.clear();
}

void Graph::setRange(double xmin, double xmax, double ymin, double ymax) {
    xMin = xmin;
    xMax = xmax;
    yMin = ymin;
    yMax = ymax;
}

void Graph::zoom(double factor) {
    double xRange = (xMax - xMin) * factor;
    double yRange = (yMax - yMin) * factor;
    double xCenter = (xMax + xMin) / 2;
    double yCenter = (yMax + yMin) / 2;

    xMin = xCenter - xRange / 2;
    xMax = xCenter + xRange / 2;
    yMin = yCenter - yRange / 2;
    yMax = yCenter + yRange / 2;
}

void Graph::pan(double dx, double dy) {
    double xRange = xMax - xMin;
    double yRange = yMax - yMin;

    xMin += dx * xRange;
    xMax += dx * xRange;
    yMin += dy * yRange;
    yMax += dy * yRange;
}

void Graph::drawAxes() {
    sf::VertexArray xAxis(sf::Lines, 2);
    sf::VertexArray yAxis(sf::Lines, 2);

    // X Axis
    float yZero = window.getSize().y - (0 - yMin) / (yMax - yMin) * window.getSize().y;
    xAxis[0].position = sf::Vector2f(0, yZero);
    xAxis[1].position = sf::Vector2f(window.getSize().x, yZero);
    xAxis[0].color = sf::Color::White;
    xAxis[1].color = sf::Color::White;

    // Y Axis
    float xZero = (0 - xMin) / (xMax - xMin) * window.getSize().x;
    yAxis[0].position = sf::Vector2f(xZero, 0);
    yAxis[1].position = sf::Vector2f(xZero, window.getSize().y);
    yAxis[0].color = sf::Color::White;
    yAxis[1].color = sf::Color::White;

    window.draw(xAxis);
    window.draw(yAxis);

    // Draw numbers on X axis
    for (int i = std::ceil(xMin); i <= std::floor(xMax); ++i) {
        sf::Text text(std::to_string(i), font, 12);
        text.setFillColor(sf::Color::White);
        text.setPosition((i - xMin) / (xMax - xMin) * window.getSize().x, yZero + 5);
        window.draw(text);
    }

    // Draw numbers on Y axis
    for (int i = std::ceil(yMin); i <= std::floor(yMax); ++i) {
        sf::Text text(std::to_string(i), font, 12);
        text.setFillColor(sf::Color::White);
        text.setPosition(xZero + 5, window.getSize().y - (i - yMin) / (yMax - yMin) * window.getSize().y);
        window.draw(text);
    }
}

void Graph::update() {
    window.clear();
    drawAxes();
    sf::VertexArray lines(sf::LinesStrip, 1000);
    double step = (xMax - xMin) / 1000;
    for (auto& func : functions) {
        for (size_t i = 0; i < 1000; ++i) {
            double x = xMin + i * step;
            double y = func->evaluate(x);
            lines[i].position = sf::Vector2f(
                    (x - xMin) / (xMax - xMin) * window.getSize().x,
                    window.getSize().y - (y - yMin) / (yMax - yMin) * window.getSize().y
            );
            lines[i].color = sf::Color::White;
        }
        window.draw(lines);
    }
    window.display();
}

sf::RenderWindow& Graph::getWindow() {
    return window;
}
