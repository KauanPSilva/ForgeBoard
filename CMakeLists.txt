cmake_minimum_required(VERSION 3.16)
project(ForgeBoard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Crow CONFIG REQUIRED)
find_package(SQLite3 REQUIRED)

add_executable(forgeboard
    src/main.cpp
    src/domain/Board.cpp
    src/application/CreateBoard.cpp
    src/infrastructure/http/BoardController.cpp
    src/infrastructure/db/SQLiteDB.cpp
    src/infrastructure/db/BoardRepositorySQLite.cpp
)

target_link_libraries(forgeboard PRIVATE Crow::Crow SQLite::SQLite3)


target_include_directories(forgeboard
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)
