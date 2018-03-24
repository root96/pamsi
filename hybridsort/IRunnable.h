//
// Created by kamil on 21.03.18.
//

#ifndef HYBRIDSORT_IRUNNABLE_H
#define HYBRIDSORT_IRUNNABLE_H

class IRunnable
{
public:
    virtual ~IRunnable() {};
    virtual void run() = 0;
};

#endif //HYBRIDSORT_IRUNNABLE_H
