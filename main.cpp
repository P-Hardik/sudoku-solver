//This is a fast and efficent Sudoku puzzle solver! Made on Jan 5, 2023 in my Christmas Break!
/*  
    This program reads the incomplete Sudoku from the user input,
    and then uses a backtracking algorithm to find a solution. 
    If a solution is found, it is printed to the console. 
    Otherwise, it prints "Unable to solve the Sudoku".
    
    Here is an example of a user input for an incomplete Sudoku:
    
    IMPORTANT: MAKE SURE THERE IS SPACE BETWEEN EACH NUMBER!!!
    0 5 0 0 0 0 0 0 4
    2 0 0 0 0 0 0 3 0
    0 0 0 2 0 0 8 0 5
    0 6 0 0 7 8 1 0 0
    0 0 0 0 0 0 0 0 0
    8 0 0 0 3 9 2 7 0
    0 0 0 4 0 0 0 0 7
    0 0 4 9 8 6 0 0 1
    0 1 0 0 0 0 0 0 0

    Please attempt to solve the Sudoku yourself first ;)
    */

#include <iostream>
#include <cstring>

using namespace std;

// Function to check if a number is valid for a given cell
bool isValid(int board[9][9], int row, int col, int num){
  // Check row and column
  for (int i = 0; i < 9; i++)
    if (board[row][i] == num || board[i][col] == num)
      return false;

  // Check subgrid
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (board[startRow + i][startCol + j] == num)
        return false;

  return true;
}

// Function to find an empty cell
bool findEmptyCell(int board[9][9], int &row, int &col){
  for (row = 0; row < 9; row++)
    for (col = 0; col < 9; col++)
      if (board[row][col] == 0)
        return true;
  return false;
}

// Function to solve the Sudoku
bool solveSudoku(int board[9][9]){
  int row, col;
  if (!findEmptyCell(board, row, col))
    return true;

  for (int num = 1; num <= 9; num++){
    if (isValid(board, row, col, num)){
      board[row][col] = num;
      if (solveSudoku(board))
        return true;
      board[row][col] = 0;
    }
  }
  return false;
}


// Function to print the Sudoku
void printSudoku(int board[9][9]){
  cout << "\nHere is the Solution for your Sudoku:" << endl;
  cout << " -----------------------" << endl;
  for (int row = 0; row < 9; row++){
    cout << "| ";
    for (int col = 0; col < 9; col++){
      cout << board[row][col] << " ";
      if ((col + 1) % 3 == 0) cout << "| ";
    }
    cout << endl;
    if ((row + 1) % 3 == 0) cout << " -----------------------" << endl;
  }
}

int main(){
  int board[9][9];
  memset(board, 0, sizeof(board));

  cout << "Enter the Sudoku: " << endl;
  for (int row = 0; row < 9; row++)
    for (int col = 0; col < 9; col++)
      cin >> board[row][col];

  if (solveSudoku(board))
    printSudoku(board);
  else
    cout << "\nUnable to solve the Sudoku" << endl;

  return 0;
}
