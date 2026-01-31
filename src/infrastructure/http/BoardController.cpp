#include "infrastructure/http/BoardController.h"
#include "domain/Board.h"

BoardController::BoardController(CreateBoard& createBoard)
    : createBoard(createBoard) {}

void BoardController::registerRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/boards")
        .methods(crow::HTTPMethod::Post)
    ([this](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("name")) {
            return crow::response(400, "Invalid body");
        }

        Board board = createBoard.execute(body["name"].s());

        crow::json::wvalue res;
        res["id"] = board.getId();
        res["name"] = board.getName();

        return crow::response(201, res);
    });

}