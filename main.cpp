#include "Main.h"


int main() {
    int Iteration = 0; // needed here to count the use of the display function
    int cycle;
    BoardType Board2;
    BoardType Board;
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            Board[i][j] = rand() % 2 == 1;
        }
    }


    cout << "Enter the number of generations to run." << endl;
    cin >> cycle;
    cout << "You will need to press a key between cycles" << endl;
    cout << "Press CTRL + C to exit at any time." << endl;
    system("sleep .5");
    system("clear");
    display(Board, Iteration);
    cout << endl << endl << endl;

    for (int i = 1; i <= cycle; i++) {
        system("sleep .5");
        system("clear");
        populate(Board, Board2);
        display(Board, Iteration);
    }

    return 0;
}