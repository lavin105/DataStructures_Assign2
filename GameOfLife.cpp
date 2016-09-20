#include <iostream>
#include "GameOfLife.h"

using namespace std;


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
    for (int Col = 1; Col <= size; Col++) {
        if (Col < 10)
            cout << Col << "  ";
        else
            cout << Col << " ";
    }
    cout << endl << endl;

    for (int Row = 1; Row <= size; Row++) {
        if (Row < 10)
            cout << Row << "   ";
        else
            cout << Row << "  ";
        for (int Col = 1; Col <= size; Col++)
            if (Board[Row][Col])
                cout << "X  ";
            else
                cout << "   ";
        cout << endl;
    }

    cout << " GENERATION: " << iteration << endl;
    iteration++;
}