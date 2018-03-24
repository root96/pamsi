#ifndef DATA_STRUCTURES_ICONTAINER_H
#define DATA_STRUCTURES_ICONTAINER_H

template <class T>
class IContainer {
public:
    ~IContainer() {}
    virtual int returnSize() = 0;
};

#endif //DATA_STRUCTURES_ICONTAINER_H
