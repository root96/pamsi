//
// Created by kamil on 21.03.18.
//

#ifndef STOP_WATCH_ISTRATEGY_H
#define STOP_WATCH_ISTRATEGY_H

#include "IRunnable.h"

template <class T>
class IStrategy {
public:
    virtual ~IStrategy() {}
    virtual void choose_strategy(IRunnable*) = 0;
};

#endif //STOP_WATCH_ISTRATEGY_H
