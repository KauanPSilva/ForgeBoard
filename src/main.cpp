#include <crow.h>
#include "application/CreateBoard.h"
#include "infrastructure/http/BoardController.h"

int main() {
    crow::SimpleApp app;

    CreateBoard createBoard;
    BoardController boardController(createBoard);
    boardController.registerRoutes(app);

    app.port(18080).multithreaded().run();
}
