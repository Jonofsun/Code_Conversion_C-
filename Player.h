#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int number;

public:
    Player(std::string name, int number);

    std::string getName() const;
    void setName(const std::string& newName);

    int getNumber() const;
    void setNumber(int newNumber);

    std::string toString() const;
};

#endif // PLAYER_H
