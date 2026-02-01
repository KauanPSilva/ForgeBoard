#pragma once
#include <string>
#include "domain/Board.h"
#include "application/ports/IBoardRepository.h"

class CreateBoard {
public:
    explicit CreateBoard(IBoardRepository& repo);

    Board execute(const std::string& name);

private:
    IBoardRepository& repo;
};
