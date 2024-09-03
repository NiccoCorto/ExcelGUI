#pragma once
#include <vector>

class Observer;

class Subject {
public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify();

private:
    std::vector<Observer*> observers;
};