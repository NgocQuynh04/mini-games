#include <iostream>
using namespace std;
const int SIZE = 3;
char board[SIZE][SIZE];
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) board[i][j] = '.';
    }
}
void printBoard() {
    cout << "  ";
    for (int j = 0; j < SIZE; j++) cout << j << " ";
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) cout << board[i][j] << " ";
        cout << endl;
    }
}
bool checkWin(int row, int col, char player) {
    // Check row
    for (int j = 0; j < SIZE; j++) {
        if (board[row][j] != player) break;
        if (j == SIZE - 1) return true;
    }
    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] != player) break;
        if (i == SIZE - 1) return true;
    }
    // Check diagonal '\'
    for (int i = 0; i < SIZE; i++) {
        if (row + i >= SIZE || col + i >= SIZE || board[row + i][col + i] != player) break;
        if (i == SIZE - 1) return true;
    }
    // Check diagonal '/'
    for (int i = 0; i < SIZE; i++) {
        if (row - i < 0 || col + i >= SIZE || board[row - i][col + i] != player) break;
        if (i == SIZE - 1) return true;
    }
    return false;
}
int main() {
    initializeBoard();
    char currentPlayer = 'X';
    int row, col;
    for (int turn = 0; turn < SIZE * SIZE; turn++) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != '.') {
            cout << "Invalid move. Try again." << endl;
            turn--;
            continue;
        }
        board[row][col] = currentPlayer;
        if (checkWin(row, col, currentPlayer)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            return 0;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    printBoard();
    cout << "It's a draw!" << endl;
    return 0;
}

