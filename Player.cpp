#include "Player.h"

Player::Player(std::string name, int number) : name(name), number(number) {}

std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string& newName) {
    name = newName;
}

int Player::getNumber() const {
    return number;
}

void Player::setNumber(int newNumber) {
    number = newNumber;
}

std::string Player::toString() const {
    return name + " - Lvl: " + std::to_string(number);
}
