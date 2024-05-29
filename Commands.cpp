#include "Commands.h"
#include <iostream>

// AddFunctionCommand
AddFunctionCommand::AddFunctionCommand(Graph &g, std::vector<std::shared_ptr<Function>> &f) : graph(g), functions(f) {}

void AddFunctionCommand::execute() {
    std::cout << "Select function type: 0 - Polynomial, 1 - Sine, 2 - Cosine, 3 - Exponential: ";
    int choice;
    std::cin >> choice;

    std::vector<double> coefficients;
    if (choice == 0) {
        std::cout << "Enter coefficients for Polynomial (a0, a1, a2, ...): ";
        double coeff;
        while (std::cin >> coeff) {
            coefficients.push_back(coeff);
            if (std::cin.peek() == '\n') break;
        }
    } else if (choice == 1 || choice == 2) {
        double amplitude, frequency;
        std::cout << "Enter amplitude and frequency: ";
        std::cin >> amplitude >> frequency;
        coefficients.push_back(amplitude);
        coefficients.push_back(frequency);
    } else if (choice == 3) {
        double base;
        std::cout << "Enter base: ";
        std::cin >> base;
        coefficients.push_back(base);
    }

    auto func = FunctionFactory::createFunction(static_cast<FunctionFactory::FunctionType>(choice), coefficients);
    functions.push_back(std::move(func));
    graph.addFunction(functions.back());
}

// ZoomCommand
ZoomCommand::ZoomCommand(Graph &g, bool z) : graph(g), zoomIn(z) {}

void ZoomCommand::execute() {
    graph.zoom(zoomIn ? 0.9 : 1.1); // Увеличение или уменьшение масштаба
    graph.update();
}

// PanCommand
PanCommand::PanCommand(Graph &g, double x, double y) : graph(g), dx(x), dy(y) {}

void PanCommand::execute() {
    graph.pan(dx, dy);
    graph.update();
}