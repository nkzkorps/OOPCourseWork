#ifndef COURSACHOOP_CONTROLLER_H
#define COURSACHOOP_CONTROLLER_H


#include "Graph.h"
#include "Commands.h"

class Controller {
public:
    static void processEvents(Graph& graph, std::vector<std::shared_ptr<Function>>& functions);
};


#endif //COURSACHOOP_CONTROLLER_H
