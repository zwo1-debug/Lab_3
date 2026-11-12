#include <iostream>

using namespace std;

void nQueen(int N);
void nQueenSolver(int **board, int N, int col);
bool isSafeMove(int **board, int N, int row, int col);
void printBoard(int **board, int N);

void nQueen(int N) {
  int **board = new int *[N];
  for (int i = 0; i < N; ++i) board[i] = new int[N];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) board[i][j] = 0;

  nQueenSolver(board, N, 0);

  for (int i = 0; i < N; ++i) delete[] board[i];
  delete[] board;
}

void nQueenSolver(int **board, int N, int col) {
  for (int row = 0; row < N; ++row) {
    if (!isSafeMove(board, N, row, col))  // skip if not safe to proceed
      continue;
    board[row][col] = 1;
    if (col == N - 1) {
      printBoard(board, N);
      board[row][col] = 0;  // to undo the change
      continue;  // exit(0); to only show one solution
    } 
    // recursive case try next column
    nQueenSolver(board, N, col + 1);
    // backtrack after search based on [row, col] is done
    board[row][col] = 0;
  }
}

bool isSafeMove(int **board, int N, int row, int col) {
    if (row) {

    }
  
    // Finish this
  // Hint: Only columns on the left needs to be checked.
  // Check row, and two diagonal lines
}

void printBoard(int **board, int N) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; j++) cout << board[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

int main() {
  int N = 4;
  nQueen(N);
  N = 5;
  nQueen(N);

  return 0;
}