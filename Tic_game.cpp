#include <iostream>
using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // There is an empty space, the game is not a draw yet
            }
        }
    }
    return true; // All spaces are filled, the game is a draw
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';

    while (true) {
        system("clear"); // For Unix-based systems
        //system("cls"); // For Windows

        cout << "Tic-Tac-Toe Game\n";
        printBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
        } else {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                system("clear"); // For Unix-based systems
                //system("cls"); // For Windows

                cout << "Tic-Tac-Toe Game\n";
                printBoard(board);

                cout << "Player " << currentPlayer << " wins!\n";
                break;
            } else if (checkDraw(board)) {
                system("clear"); // For Unix-based systems
                //system("cls"); // For Windows

                cout << "Tic-Tac-Toe Game\n";
                printBoard(board);

                cout << "It's a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
