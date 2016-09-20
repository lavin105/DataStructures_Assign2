#include <iostream>
#include <cstdlib>
#include <stdlib.h>  // You might be able to get away without this one.

using namespace std;

const int size = 24;

typedef bool BoardType[size][size];

// Function prototypes:

void display(BoardType Board, int &iteration);

bool Life(BoardType Board);

void populate(BoardType Board, BoardType Board2);

void ClearScreen();

// A function prototype can't be used with an inline function (see below for function NumLiveNeighbors).  Just be careful to use it only after the function is defined.

int main() {
    int Iteration = 0; // needed here to count the use of the display function
    int cycle;
    BoardType Board2;
    BoardType Board =
            {
                    {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0,},
                    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1,},
                    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0,},
                    {0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1,},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,},
                    {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1,},
                    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,},
                    {0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1,},
                    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1,},
                    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1,},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,},
                    {0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1,},
                    {0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,},
                    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1,},
                    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,},
                    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1,},
                    {0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1,},
                    {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
                    {0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1,},
                    {0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0,},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,},
                    {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0,},
            };

    cout << "Enter the number of generations to run." << endl;
    cin >> cycle;
    cout << "You will need to press a key between cycles" << endl;
    cout << "Press CTRL + C to exit at any time.";
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

/* Given:   Board	A 2D array of type Bool, serving as the matrix for our game
            Row		An integer defining the row of the cell being checked.
            Col		An integer defining the column of the cell being checked.
   Task:	 Calculate the number of live neighboring cells.
   Return:  In the function name, return the count of the number of live neighbors.
*/
inline int NumLiveNeighbors(BoardType Board, int Row, int Col) {
    // Write the code for this function.  There are several ways to cout the
    // number of neighbors.  Be careful not to go beyond the edges of the
    // Board.  That means there are several special cases to consider, such
    // as when Row and Col are for one of the corners of the Board, or when Row
    // and Col specify another location on the edge of the Board.


    return 0;
}

/*	Given:  Board	A 2D array of type Bool, serving as the matrix for our game
            Row		An integer defining the row of the cell being checked.
            Col		An integer defining the column of the cell being checked.
   Task:	 Calculate the number of live neighboring cells using checkmid,
            checktop, checkbottom. Determine if the cell being studied will be
            alive or dead for the next generation (See rules Above)
   Return:  True     if the cell will be live for the next generation
            False    if the cell will be dead for the next generation,
*/
bool Life(BoardType Board, int Row, int Col) {
    int live = NumLiveNeighbors(Board, Row, Col);

    if (Board[Row][Col])   // if Board[Row][Col] is true then...
    {
        // If the number of live neigbors is too large or small (see the rules)
        // then return false to say that the cell will die.
        // Otherwise, return true to say the the cell will remain alive.

    } else    // if Board[Row][Col] is false then...
    {
        // If the number of live neighbors is just right, return true to say
        // that this dead cell will come to life.  Otherwise return false to say
        // that this dead cell stays dead.  (Again, refer to the rules.)

    }
    return false;
}

// The rest of the program has been written for you.  Don't change it. ************

/*	Given: Board	A 2D array of type Bool, serving as the matrix for our game.
            Board2	Board2 will be populated as the function Life determines
                     whether the cell is live or dead in the next generation,
                     after Board2 is populated, it will be copied into Board, to
                     represent itself as the current generation.
   Task:	Populate Board2 with the values from Life, representing the next
           generation. Copy the populated Board2 into Board, the contents of
           Board2 are now the current generation.
   Return:  Board    Containing the new generation of cells.
            Board2   Containing a copy of Board.
*/
void ClearScreen() {
    int n;
    for (n = 0; n < 10; n++)
        printf("\n\n\n\n\n\n\n\n\n\n");
}

void populate(BoardType Board, BoardType Board2) {
    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            Board2[row][col] = Life(Board, row, col);

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            Board[row][col] = Board2[row][col];
}

/*	Given:  Board     The Array to Display
            iteration  A count of cycles that the function has run.
   Task:	  Display the contents of Board in an easy-to-read format.
   Return:  Iteration   Updated count of number of generations displayed.
*/
void display(BoardType Board, int &iteration) {
    cout << "    ";
    for (int Col = 0; Col < size; Col++) {
        if (Col < 10)
            cout << Col << "  ";
        else
            cout << Col << " ";
    }
    cout << endl << endl;

    for (int Row = 0; Row < size; Row++) {
        if (Row < 10)
            cout << Row << "   ";
        else
            cout << Row << "  ";
        for (int Col = 0; Col < size; Col++)
            if (Board[Row][Col])
                cout << "X  ";
            else
                cout << "   ";
        cout << endl;
    }

    cout << " GENERATION: " << iteration << endl;
    iteration++;
}