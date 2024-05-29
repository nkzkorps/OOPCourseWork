#ifndef COURSACHOOP_COMMANDS_H
#define COURSACHOOP_COMMANDS_H


#include "Graph.h"
#include <vector>
#include <memory>

// Паттерн Команда
class Command {
public:
    virtual void execute() = 0;

    virtual ~Command() = default;
};

class AddFunctionCommand : public Command {
    Graph &graph;
    std::vector<std::shared_ptr<Function>> &functions;
public:
    AddFunctionCommand(Graph &g, std::vector<std::shared_ptr<Function>> &f);

    void execute() override;
};

class ZoomCommand : public Command {
    Graph &graph;
    bool zoomIn;
public:
    ZoomCommand(Graph &g, bool z);

    void execute() override;
};

class PanCommand : public Command {
    Graph &graph;
    double dx, dy;
public:
    PanCommand(Graph &g, double x, double y);

    void execute() override;
};


#endif //COURSACHOOP_COMMANDS_H
