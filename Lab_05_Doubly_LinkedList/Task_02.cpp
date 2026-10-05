#include <iostream>
#include <string>

class PlayerNode {
public:
    std::string name;
    PlayerNode* next;

    PlayerNode(std::string playerName) {
        name = playerName;
        next = nullptr;
    }
};

class GameTurns {
private:
    PlayerNode* head;
    PlayerNode* tail;
    int playerCount;

public:
    GameTurns() {
        head = nullptr;
        tail = nullptr;
        playerCount = 0;
    }

    void addPlayer(const std::string& name) {
        PlayerNode* newPlayer = new PlayerNode(name);

        if (head == nullptr) {
            head = newPlayer;
            tail = newPlayer;
            newPlayer->next = head;
        }
        else {
            tail->next = newPlayer;
            tail = newPlayer;
            tail->next = head;
        }
        playerCount++;
    }

    void displaySingleRound() const {
        if (head == nullptr) return;

        std::cout << "--- Single Round of Turns ---\n";
        PlayerNode* current = head;
        int turn = 1;

        do {
            std::cout << "Turn " << turn++ << ": " << current->name << "'s turn\n";
            current = current->next;
        } while (current != head);

        std::cout << "\n";
    }

    void demonstrateCircularLoop(int extraTurns = 2) const {
        if (head == nullptr) return;

        std::cout << "--- Circular Continuation Demo ---\n";
        PlayerNode* current = head;
        int totalTurns = playerCount + extraTurns;

        for (int i = 1; i <= totalTurns; ++i) {
            std::cout << "Turn " << i << ": " << current->name << "'s turn";
            if (i == playerCount + 1) {
                std::cout << "  <-- (Wrapped back to the 1st player!)";
            }
            std::cout << "\n";
            current = current->next;
        }
        std::cout << "\n";
    }

    ~GameTurns() {
        if (head == nullptr) return;

        PlayerNode* current = head;
        tail->next = nullptr;

        while (current != nullptr) {
            PlayerNode* nextPlayer = current->next;
            delete current;
            current = nextPlayer;
        }
    }
};

int main() {
    GameTurns game;

    game.addPlayer("Alice");
    game.addPlayer("Bob");
    game.addPlayer("Charlie");
    game.addPlayer("Diana");
    game.addPlayer("Ethan");

    game.displaySingleRound();
    game.demonstrateCircularLoop(2);

    return 0;
}