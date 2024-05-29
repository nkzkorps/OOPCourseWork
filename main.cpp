#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "Controller.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Function Plotter");
    Graph graph(window);
    std::vector<std::shared_ptr<Function>> functions;

    graph.update();

    while (window.isOpen()) {
        Controller::processEvents(graph, functions);
        graph.update();
    }

    return 0;
}
