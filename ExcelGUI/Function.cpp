#include "Function.h"
#include <numeric>
#include <algorithm>

Function::Function(Type type, const std::vector<Cell*>& cells) : type(type), cells(cells) {
    for (Cell* cell : cells) {
        cell->attach(this);
    }
    update(nullptr);  // Calculate initial value
}

void Function::update(Subject* subject) {
    switch (type) {
    case SUM:
        value = std::accumulate(cells.begin(), cells.end(), 0, [](int sum, Cell* cell) {
            return sum + cell->getValue();
            });
        break;
    case MEAN:
        value = std::accumulate(cells.begin(), cells.end(), 0, [](int sum, Cell* cell) {
            return sum + cell->getValue();
            }) / cells.size();
        break;
    case MIN:
        value = (*std::min_element(cells.begin(), cells.end(), [](Cell* a, Cell* b) {
            return a->getValue() < b->getValue();
            }))->getValue();
        break;
    case MAX:
        value = (*std::max_element(cells.begin(), cells.end(), [](Cell* a, Cell* b) {
            return a->getValue() > b->getValue();
            }))->getValue();
        break;
    }
}