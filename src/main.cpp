#include <crow.h>
#include "domain/Board.h"
#include "application/CreateBoard.h"

int main() {
    CreateBoard createBoard;
    Board board = createBoard.execute("Projeto ForgeBoard");

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([&board](){
        return "Board ativo: " + board.getName();
    });

    app.port(18080).multithreaded().run();
}
