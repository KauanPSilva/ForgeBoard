cmake_minimum_required(VERSION 3.16)
project(ForgeBoard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Crow CONFIG REQUIRED)

add_executable(forgeboard
    src/main.cpp
    src/domain/Board.cpp
)

target_link_libraries(forgeboard
    PRIVATE Crow::Crow
)
