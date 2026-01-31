#pragma once
#include <string>

class Board {
private:
    int id;
    std::string name;

public:
    Board(int id, const std::string& name);

    int getId() const;
    const std::string& getName() const;

    void rename(const std::string& newName);
};
