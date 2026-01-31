#include "Board.h"

Board::Board(int id, const std::string& name)
    : id(id), name(name) {}

int Board::getId() const {
    return id;
}

const std::string& Board::getName() const {
    return name;
}

void Board::rename(const std::string& newName) {
    if(!newName.empty()) {
        name = newName;
    }
}