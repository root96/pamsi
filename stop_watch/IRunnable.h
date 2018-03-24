#ifndef STOP_WATCH_IRUNNABLE_H
#define STOP_WATCH_IRUNNABLE_H

template <class T>
class IRunnable
{
public:
    virtual ~IRunnable() {};
    virtual void run() = 0;
};

#endif //STOP_WATCH_IRUNNABLE_H
