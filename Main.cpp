#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Player.h"

std::vector<Player> players;

void DisplayAllPlayers();
void DisplayPlayersOdd();
void DisplayLetterIndex();
void AddPlayer();
void Menu();

int main() {
    players.push_back(Player("Nami", 20));
    players.push_back(Player("Luffy", 99));
    players.push_back(Player("Zoro", 96));
    players.push_back(Player("Robin", 77));
    players.push_back(Player("Usopp", 3));

    std::cout << "Welcome: Press anything\n";
    std::cin.get();
    Menu();

    return 0;
}

void Menu() {
    bool isRunning = true;
    while (isRunning) {
        std::cout << "\n1 - Display All Players\n";
        std::cout << "2 - Display Players with an Odd Number\n";
        std::cout << "3 - Display Players starting with a letter\n";
        std::cout << "4 - Add Player\n";
        std::cout << "e - Exit\n";
        std::cout << "USER selection: ";

        std::string userInput;
        std::getline(std::cin, userInput);

        if (userInput == "1") {
            DisplayAllPlayers();
        } else if (userInput == "2") {
            DisplayPlayersOdd();
        } else if (userInput == "3") {
            DisplayLetterIndex();
        } else if (userInput == "4") {
            AddPlayer();
        } else if (userInput == "e") {
            std::cout << "Good Bye\n";
            exit(1);
        } else {
            std::cout << "\nInvalid selection\n";
        }
    }
}

void DisplayAllPlayers() {
    std::cout << "\nAll Players:\n";
    for (const auto& p : players) {
        std::cout << p.toString() << std::endl;
    }
}

void DisplayPlayersOdd() {
    std::cout << "\nPlayers with Odd Numbers:\n";
    for (const auto& p : players) {
        if (p.getNumber() % 2 != 0) {
            std::cout << p.getName() << " - Lvl: " << p.getNumber() << std::endl;
        }
    }
}

void DisplayLetterIndex() {
    std::cout << "Enter a letter: ";
    char letter;
    std::cin >> letter;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    letter = tolower(letter);

    std::cout << "\nPlayers with Names Starting with '" << letter << "':\n";
    for (const auto& p : players) {
        if (tolower(p.getName()[0]) == letter) {
            std::cout << p.getName() << " - Lvl: " << p.getNumber() << std::endl;
        }
    }
}

void AddPlayer() {
    std::cout << "Enter player's name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter player's Level: ";
    int number;
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    players.push_back(Player(name, number));
    std::cout << "Player " << name << " added successfully.\n";
}
