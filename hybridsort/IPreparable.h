//
// Created by kamil on 21.03.18.
//

#ifndef HYBRIDSORT_IPREPARABLE_H
#define HYBRIDSORT_IPREPARABLE_H

class IPreparable {
public:
    virtual ~IPreparable() {};
    virtual void clear() = 0;
    virtual void prepare(int) = 0;
    virtual void prepare(int[], int) = 0;
};

#endif //HYBRIDSORT_IPREPARABLE_H
