#include <crow.h>
#include <filesystem>

#include "application/CreateBoard.h"
#include "infrastructure/http/BoardController.h"
#include "infrastructure/db/SQLiteDB.h"
#include "infrastructure/db/BoardRepositorySQLite.h"

int main() {
    crow::SimpleApp app;

    std::filesystem::create_directories("data");

    SQLiteDB db("data/forgeboard.db");
    db.initSchema();

    BoardRepositorySQLite boardRepo(db);
    CreateBoard createBoard(boardRepo);

    BoardController boardController(createBoard, boardRepo);
    boardController.registerRoutes(app);

    app.port(18080).multithreaded().run();
}
