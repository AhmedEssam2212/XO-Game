#include <iostream>
#include <stdlib.h>
#include "game.h"


using namespace std;

bool win(const game &xo) {
    if (xo.winner() != '-') {
        if (xo.winner() == 'X')
            xo.view(), cout << "\n\t\tYOU ARE THE WINNER ! ! !\n\n";
        else
            xo.view(), cout << "\n\t\tCOMPUTER IS THE WINNER ! ! !\n\n";
        return true;
    }
    return false;
}

bool noWin(const game &xo) {
    if (xo.fail()) {
        xo.view(), cout << "\n\t\t\tNO WIN     :(\n";
        return true;
    }
    return false;
}

void play() {
    srand(time(NULL));
    string choice = "yes";
    while (choice == "yes") {
        game xo;
        xo.first();
        while (true) {
            xo.view();
            int cell;
            cout << "Please enter number of cell: ";
            cin >> cell;
            while (cell < 1 || cell > 9) {
                cout << "Please enter a valid choice: ";
                cin >> cell;
            }
            xo.player(cell, 'X');
            if (win(xo))
                break;
            if (noWin(xo))
                break;
            xo.computer('O');
            if (win(xo))
                break;
            if (noWin(xo))
                break;
        }
        cout << "Do you want to play again?\n plese enter \"yes\" or \"no\"\n";
        cin >> choice;
    }
}

int main() {
    play();
}
