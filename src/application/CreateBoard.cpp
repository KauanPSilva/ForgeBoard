#include "application/CreateBoard.h"

CreateBoard::CreateBoard(IBoardRepository& repo)
    : repo(repo) {}

Board CreateBoard::execute(const std::string& name) {
    return repo.create(name);
}
