#include "infrastructure/http/BoardController.h"

BoardController::BoardController(CreateBoard& createBoard, IBoardRepository& repo)
    : createBoard(createBoard), repo(repo) {}

void BoardController::registerRoutes(crow::SimpleApp& app) {

    // POST /boards
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

    // GET /boards/<id>
    CROW_ROUTE(app, "/boards/<int>")
        .methods(crow::HTTPMethod::Get)
    ([this](int id) {
        auto boardOpt = repo.findById(id);
        if (!boardOpt.has_value()) {
            return crow::response(404, "Board not found");
        }

        const Board& board = boardOpt.value();
        crow::json::wvalue res;
        res["id"] = board.getId();
        res["name"] = board.getName();
        return crow::response(200, res);
    });
}
