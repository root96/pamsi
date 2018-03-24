//
// Created by kamil on 21.03.18.
//

#ifndef HYBRIDSORT_ISORT_H
#define HYBRIDSORT_ISORT_H

class ISortable {
public:
    virtual ~ISortable() {}
    virtual std::string name() = 0;
    virtual void sort() = 0;
};

#endif //HYBRIDSORT_ISORT_H
