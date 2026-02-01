#pragma once
#include <mutex>
#include "application/ports/IBoardRepository.h"
#include "infrastructure/db/SQLiteDB.h"

class BoardRepositorySQLite : public IBoardRepository {
public:
    explicit BoardRepositorySQLite(SQLiteDB& db);

    Board create(const std::string& name) override;
    std::optional<Board> findById(int id) override;

private:
    SQLiteDB& db;
    std::mutex mtx;
};