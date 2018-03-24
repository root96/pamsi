#ifndef STOP_WATCH_IPREPARABLE_H
#define STOP_WATCH_IPREPARABLE_H

template <class T>
class IPreparable {
public:
    virtual ~IPreparable() {};
    virtual void prepare(const T&) = 0;
    virtual const std::string getName() const = 0;

};

#endif //STOP_WATCH_IPREPARABLE_H
