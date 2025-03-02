#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class SnakeLadder {
    int currentPosition;
   

    // Arrays for ladder start and respective jumps
    int ladderStart[6] = {5, 14, 42, 53, 64, 75};
    int ladderJump[6] = {53, 35, 18, 19, 19, 19};

    // Arrays for snake start and respective drops
    int snakeStart[6] = {45, 51, 38, 91, 97, 65};
    int snakeDrop[6] = {-38, -41, -18, -18, -36, -9};

public:
string name;
    SnakeLadder() {
        currentPosition = 0;
    }
    SnakeLadder(string n){
      name=n;
    }

    int rollDice() {
        return 1 + rand() % 6;
    }

    void updatePosition(int diceValue) {
        if (currentPosition + diceValue > 100) {
            cout << "Roll exceeds 100. Try again next turn!" << endl;
            return;
        }

        currentPosition += diceValue;

        // Check for ladders
        for (int i = 0; i < 6; i++) {
            if (currentPosition == ladderStart[i]) {
                cout << "Ladder! Climbed from " << currentPosition << " to " << (currentPosition + ladderJump[i]) << endl;
                currentPosition += ladderJump[i];
                break;
            }
        }

        // Check for snakes
        for (int i = 0; i < 6; i++) {
            if (currentPosition == snakeStart[i]) {
                cout << "Oops! Snake bite. Fell from " << currentPosition << " to " << (currentPosition + snakeDrop[i]) << endl;
                currentPosition += snakeDrop[i];
                break;
            }
        }
    }

    int getPosition() {
        return currentPosition;
    }

    bool checkWin() {
        return currentPosition == 100;
    }

    void display() {
        cout << "Current position: " << currentPosition << endl;
    }
};

int main() {
    srand(time(0));

    SnakeLadder l1("Lucky"), l2("kumar");
    int turn = 0;

    while (true) {
       // system("cls"); // Clear screen before each turn

        if (turn == 0) {
            cout << "\n"<<l1.name<<" turn!" << endl;
            l1.display();
            cout << "Press Enter to roll the dice: ";
            cin.ignore();
            int diceValue = l1.rollDice();
            cout << l1.name<<" rolled a " << diceValue << endl;
            l1.updatePosition(diceValue);
            l1.display();
            if (l1.checkWin()) {
                cout << l1.name<<"wins!" << endl;
                break;
            }
            turn = 1; // Switch to Player 2
        } 
        else {
            cout << "\n"<<l2.name<<" turn!" << endl;
            l2.display();
            cout << "Press Enter to roll the dice: ";
            cin.ignore();
            int diceValue = l2.rollDice();
            cout << l2.name<<" rolled a " << diceValue << endl;
            l2.updatePosition(diceValue);
            l2.display();
            if (l2.checkWin()) {
                cout << l2.name<<"wins!" << endl;
                break;
            }
            turn = 0; // Switch to Player 1
        }
    }

    return 0;
}
