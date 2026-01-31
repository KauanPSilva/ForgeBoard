#include <crow.h>
#include "domain/Board.h"

int main() {
    Board board(1, "Projeto ForgeBoard");

    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([&board](){
        return "Board ativo: " + board.getName();
    });

    app.port(18080).multithreaded().run();
}
