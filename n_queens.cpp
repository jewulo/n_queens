// n_queens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// https://www.tutorialspoint.com/cplusplus-program-to-solve-n-queen-problem
//
#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 8; // nasty global variable

void printBoard(int board[N][N])
{
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isValid(int board[N][N], int row, int col)
{
	for (int i = 0; i < col; i++) {
		if (board[row][i])	// check whether there is a queen to the left
			return false;
	}

	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
		if (board[i][j])	// check whether there is a queen to the left upper diagonal
			return false;
	}

	for (int i = row, j = col; j >= 0 && i < N; ++i, --j) {
		if (board[i][j])	// check whether there is a queen to the left lower diagonal
			return false;
	}

	return true;
}

bool solveNQueen(int board[N][N], int col)
{
	if (col >= N) // if N queens are placed successfully
		return true; // then completed

	for (int i = 0; i < N; ++i) {
		if (isValid(board, i, col)) {
			board[i][col] = 1; // if validated, place queen in position [i,col]
			if (solveNQueen(board, col + 1)) // go for the other columns recursively
				return true; // if solution is found for other columns
			board[i][col] = 0; // when no place is vacant remove that queen
		}
	}

	return false; // when no solution is found
}

bool checkSolution()
{
	int board[N][N];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			board[i][j] = 0;
	if (solveNQueen(board, 0) == false) {
		cout << "Solution does not exist!\n";
		return false;
	}
	printBoard(board);
	return true;
}

int main()
{
	checkSolution();
	cin.get();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
