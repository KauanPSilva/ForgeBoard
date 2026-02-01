#pragma once
#include <crow.h>
#include "application/CreateBoard.h"
#include "application/ports/IBoardRepository.h"

class BoardController {
public:
    BoardController(CreateBoard& createBoard, IBoardRepository& repo);
    void registerRoutes(crow::SimpleApp& app);

private:
    CreateBoard& createBoard;
    IBoardRepository& repo;
};
