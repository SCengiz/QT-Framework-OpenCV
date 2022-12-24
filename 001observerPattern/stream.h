#ifndef STREAM_H
#define STREAM_H

#include<memory>
#include<list>
#include<algorithm>
#include<iostream>
#include<observer.h>

class Observer;

class Stream
{
public:
    Stream();
    ~Stream();

    void attach(Observer*);
    void detach(Observer*);

    void incrementStreamCount();
    void decrementStreamCount();
    int getStreamCount() const;
    std::list<Observer*> getListOfObserver() const;
private:
    std::list<Observer*> listOfObserver_;
    int streamCount_;
};

#endif // STREAM_H
