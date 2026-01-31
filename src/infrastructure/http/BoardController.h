#pragma once
#include <crow.h>
#include "application/CreateBoard.h"

class BoardController {
public:
    explicit BoardController(CreateBoard& createBoard);
    void registerRoutes(crow::SimpleApp& app);

private:
    CreateBoard& createBoard;
    
};