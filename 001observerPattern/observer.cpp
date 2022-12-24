#include "observer.h"

Observer::Observer(Stream* stream, QString& streamId)
    : stream_(stream), streamId_(streamId) {
    std::cout << "Observer ctor called" << std::endl;
    this->stream_->incrementStreamCount();
    this->stream_->attach(this);
}

Observer::~Observer() {
    std::cout << "Observer dtor called" << std::endl;
    std::cout << "OBSERVER DTOR ADDR: " << this << std::endl;
}

void Observer::removeObserverFromStream() {
    this->stream_->detach(this);
    this->stream_->decrementStreamCount();
}

void Observer::callStream() {
    std::cout << "address of Stream: " << this->stream_ << std::endl;
}

void Observer::callObserver() {
    std::cout << "address of Observer: " << this << std::endl;
}

QString Observer::getStreamId() const {
    return this->streamId_;
}

