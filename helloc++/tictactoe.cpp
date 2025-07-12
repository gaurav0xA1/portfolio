#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int SIZE = 3; // Size of the board (3x3)

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    bool gameOver;

public:
    TicTacToe() : board(SIZE, vector<char>(SIZE, ' ')), currentPlayer('X'), gameOver(false) {}

    void printBoard() const {
        cout << "\n";
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << " " << board[i][j] << " ";
                if (j < SIZE - 1) cout << "|";
            }
            cout << "\n";
            if (i < SIZE - 1) {
                cout << "-----------\n";
            }
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool checkWin() const {
        // Check rows and columns
        for (int i = 0; i < SIZE; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }

        return false;
    }

    bool checkDraw() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void playGame() {
        cout << "Welcome to Tic Tac Toe!\n";
        cout << "Player 1: X, Player 2: O\n";

        while (!gameOver) {
            printBoard();
            cout << "Player " << currentPlayer << "'s turn.\n";

            int row, col;
            while (true) {
                cout << "Enter row (1-3) and column (1-3): ";
                cin >> row >> col;

                // Convert to 0-based index
                row--;
                col--;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter numbers only.\n";
                } else if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
                    cout << "Invalid position. Row and column must be between 1 and 3.\n";
                } else if (!makeMove(row, col)) {
                    cout << "That position is already taken. Try again.\n";
                } else {
                    break;
                }
            }

            if (checkWin()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                printBoard();
                cout << "The game is a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Game over. Thanks for playing!\n";
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}