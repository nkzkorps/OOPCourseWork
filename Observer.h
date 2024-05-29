//
// Created by Anna on 28.05.2024.
//

#ifndef COURSACHOOP_OBSERVER_H
#define COURSACHOOP_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};


#endif //COURSACHOOP_OBSERVER_H
