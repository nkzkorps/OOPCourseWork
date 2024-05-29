#ifndef COURSACHOOP_GRAPH_H
#define COURSACHOOP_GRAPH_H


#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Observer.h"
#include "Functions.h"

class Graph : public Observer {
    std::vector<std::shared_ptr<Function>> functions;
    sf::RenderWindow& window;
    sf::Font font;
    double xMin, xMax, yMin, yMax;
public:
    Graph(sf::RenderWindow& win);
    void addFunction(std::shared_ptr<Function> func);
    void clearFunctions();
    void setRange(double xmin, double xmax, double ymin, double ymax);
    void zoom(double factor);
    void pan(double dx, double dy);
    void drawAxes();
    void update() override;
    sf::RenderWindow& getWindow();
};


#endif //COURSACHOOP_GRAPH_H
