#include "infrastructure/db/SQLiteDB.h"
#include <stdexcept>

SQLiteDB::SQLiteDB(const std::string& path) {
    if (sqlite3_open(path.c_str(), &db) != SQLITE_OK) {
        std::string msg = db ? sqlite3_errmsg(db) : "unknown sqlite error";
        throw std::runtime_error("sqlite open failed: " + msg);
    }
}

SQLiteDB::~SQLiteDB() {
    if (db) sqlite3_close(db);
}

void SQLiteDB::initSchema() {
    const char* sql = R"SQL(
        CREATE TABLE IF NOT EXISTS boards (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL
        );
    )SQL";

    char* errMsg = nullptr;
    if(sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::string msg = errMsg ? errMsg : "unknown sqlite error";
        sqlite3_free(errMsg);
        throw std::runtime_error("sqlite schema init falied: " + msg);
    }
}