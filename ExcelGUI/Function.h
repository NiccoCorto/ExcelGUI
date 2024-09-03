#pragma once
#include "Observer.h"
#include "Cell.h"
#include <vector>

class Function : public Observer {
public:
    enum Type { SUM, MEAN, MIN, MAX };

    Function(Type type, const std::vector<Cell*>& cells);
    int getValue() const { return value; }

    void update(Subject* subject) override;

private:
    Type type;
    int value;
    std::vector<Cell*> cells;
};