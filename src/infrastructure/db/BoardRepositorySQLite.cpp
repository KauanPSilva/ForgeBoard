#include "infrastructure/db/BoardRepositorySQLite.h"
#include <stdexcept>

BoardRepositorySQLite::BoardRepositorySQLite(SQLiteDB& db)
    : db(db) {}

Board BoardRepositorySQLite::create(const std::string& name) {
    std::lock_guard<std::mutex> lock(mtx);

    const char* sql = "INSERT INTO boards(name) VALUES(?);";
    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db.handle(), sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("sqlite prepare failed (insert)");
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("sqlite step failed (insert)");
    }

    sqlite3_finalize(stmt);

    int id = static_cast<int>(sqlite3_last_insert_rowid(db.handle()));
    return Board(id, name);
}

std::optional<Board> BoardRepositorySQLite::findById(int id) {
    std::lock_guard<std::mutex> lock(mtx);

    const char* sql = "SELECT id, name FROM boards WHERE id = ?;";
    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db.handle(), sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("sqlite prepare failed (select)");
    }

    sqlite3_bind_int(stmt, 1, id);

    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        int boardId = sqlite3_column_int(stmt, 0);
        const unsigned char* text = sqlite3_column_text(stmt, 1);
        std::string name = text ? reinterpret_cast<const char*>(text) : "";

        sqlite3_finalize(stmt);
        return Board(boardId, name);
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}
