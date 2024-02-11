#include <iostream>
#include <string>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

string player1Name;
string player2Name;

bool isTie = false;

void displayBoard();
void getPlayerNames();
void makeMove();
bool checkWin();
bool checkTie();
bool playAgain();

int main() {
    getPlayerNames();

    bool replay = true;
    while (replay) {
        currentPlayer = 'X';
        isTie = false;

        while (!checkWin() && !isTie) {
            displayBoard();
            makeMove();
        }

        displayBoard();

        if (isTie) {
            cout << "It's a tie!\n";
        } else {
            if (currentPlayer == 'X') {
                cout << player2Name << " wins!\n";
            } else {
                cout << player1Name << " wins!\n";
            }
        }

        replay = playAgain();
    }

    return 0;
}

void displayBoard() {
    system("cls");
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << " ---|---|---\n";
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << " ---|---|---\n";
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
}

void getPlayerNames() {
    cout << "Enter the name of the first player: ";
    getline(cin, player1Name);
    cout << "Enter the name of the second player: ";
    getline(cin, player2Name);
}

void makeMove() {
    int position;
    cout << (currentPlayer == 'X' ? player1Name : player2Name) << ", enter your move (1-9): ";
    cin >> position;

    if (position < 1 || position > 9) {
        cout << "Invalid move! Please enter a number between 1 and 9.\n";
        return;
    }

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "That position is already taken! Please choose another.\n";
        return;
    }

    board[row][col] = currentPlayer;

    if (checkWin()) {
        return;
    }

    if (checkTie()) {
        isTie = true;
        return;
    }

    currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
}

bool checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

bool checkTie() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
