#include "stream.h"

Stream::Stream() {
    std::cout << "Stream ctor called" << std::endl;
}

Stream::~Stream() {
    std::cout << "Stream dtor called" << std::endl;
    std::cout << "STREAM DTOR ADDR: " << this << std::endl;
}

void Stream::attach(Observer* observer) {
    this->listOfObserver_.emplace_back(observer);
}

void Stream::detach(Observer* observer) {
    observer = nullptr;
    this->listOfObserver_.remove(observer);
}

void Stream::incrementStreamCount() {
    ++this->streamCount_;
}

void Stream::decrementStreamCount() {
    --this->streamCount_;
}

int Stream::getStreamCount() const {
    return this->streamCount_;
}

std::list<Observer *> Stream::getListOfObserver() const {
    return this->listOfObserver_;
}
