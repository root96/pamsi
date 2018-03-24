//
// Created by kamil on 21.03.18.
//

#ifndef HYBRIDSORT_ISTRATEGY_H
#define HYBRIDSORT_ISTRATEGY_H

class IStrategy {
public:
    virtual ~IStrategy() {}
    virtual void strategy() = 0;
};

#endif //HYBRIDSORT_ISTRATEGY_H
