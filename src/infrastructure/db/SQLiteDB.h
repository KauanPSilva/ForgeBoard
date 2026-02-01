#pragma once
#include <sqlite3.h>
#include <string>

class SQLiteDB {
public:
    explicit SQLiteDB(const std::string& path);
    ~SQLiteDB();

    SQLiteDB(const SQLiteDB&) = delete;
    SQLiteDB& operator=(const SQLiteDB&) = delete;

    sqlite3* handle() const { return db; }
    void initSchema();

private:
    sqlite3* db = nullptr;
};