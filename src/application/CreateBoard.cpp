#include "application/CreateBoard.h"

Board CreateBoard::execute(const std::string& name) {
    return Board(1, name);
}