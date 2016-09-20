
const int size = 50;

typedef bool BoardType[size][size];

void display(BoardType Board, int &iteration);

bool Life(BoardType Board, int Row, int Col);

void populate(BoardType Board, BoardType Board2);

