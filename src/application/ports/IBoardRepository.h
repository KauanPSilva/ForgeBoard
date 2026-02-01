#pragma once
#include <optional>
#include <string>
#include "domain/Board.h"

class IBoardRepository {
public:
    virtual  ~IBoardRepository() = default;

    virtual Board create(const std::string& name) = 0;
    virtual std::optional<Board> findById(int id) = 0;
};