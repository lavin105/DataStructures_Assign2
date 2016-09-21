#include "main.h"


int main() {
	GameOfLife sim;
    int Iteration = 0; // needed here to count the use of the display function
    int cycle;
	GameOfLife::BoardType Board2;
	GameOfLife::BoardType Board;
	for (int i = 1; i < GameOfLife::size; i++)
	{
		for (int j = 1; j < GameOfLife::size; j++)
		{

			Board[i][j] = ((double) rand() / (RAND_MAX)) >= .5;
        }
    }


    cout << "Enter the number of generations to run." << endl;
    cin >> cycle;
    cout << "You will need to press a key between cycles" << endl;
    cout << "Press CTRL + C to exit at any time." << endl;
    system("sleep .5");
    system("clear");
	sim.display(Board, Iteration);
    cout << endl << endl << endl;

    for (int i = 1; i <= cycle; i++) {
        system("sleep .5");
        system("clear");
		sim.populate(Board, Board2);
		sim.display(Board, Iteration);
    }

    return 0;
}