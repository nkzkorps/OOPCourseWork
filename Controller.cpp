#include "Controller.h"

void Controller::processEvents(Graph &graph, std::vector<std::shared_ptr<Function>> &functions) {
    sf::RenderWindow &window = graph.getWindow();
    sf::Event event;
    while (window.pollEvent(event)) {
        Command *command = nullptr;
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                graph.clearFunctions();
                functions.clear();
                command = new AddFunctionCommand(graph, functions);
            } else if (event.key.code == sf::Keyboard::N) {
                command = new AddFunctionCommand(graph, functions); // Добавить новый график
            } else if (event.key.code == sf::Keyboard::Add || event.key.code == sf::Keyboard::Equal) {
                command = new ZoomCommand(graph, true); // Увеличение масштаба
            } else if (event.key.code == sf::Keyboard::Subtract || event.key.code == sf::Keyboard::Dash) {
                command = new ZoomCommand(graph, false); // Уменьшение масштаба
            } else if (event.key.code == sf::Keyboard::Left) {
                command = new PanCommand(graph, -0.1, 0); // Поворот влево
            } else if (event.key.code == sf::Keyboard::Right) {
                command = new PanCommand(graph, 0.1, 0); // Поворот вправо
            } else if (event.key.code == sf::Keyboard::Up) {
                command = new PanCommand(graph, 0, 0.1); // Поворот вверх
            } else if (event.key.code == sf::Keyboard::Down) {
                command = new PanCommand(graph, 0, -0.1); // Поворот вниз
            }
        }
        if (command) {
            command->execute();
            delete command;
        }
    }
}