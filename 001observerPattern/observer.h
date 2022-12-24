#ifndef OBSERVER_H
#define OBSERVER_H

#include<stream.h>
#include<QString>

class Stream;

class Observer
{
public:
    Observer(Stream*, QString&);
    ~Observer();

    void removeObserverFromStream();

    void callStream();
    void callObserver();

    QString getStreamId() const;

private:
    Stream* stream_;
    QString streamId_;
};

#endif // OBSERVER_H
