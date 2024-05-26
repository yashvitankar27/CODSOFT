#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void initializeBoard(vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        board.push_back(EMPTY);
    }
}

void displayBoard(const vector<char>& board) {
    cout<<endl<<endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool makeMove(vector<char>& board, char player) {
    int move;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> move;

    if (move < 1 || move > 9 || board[move - 1] != EMPTY) {
        cout << "Invalid move, try again." << endl;
        return false;
    }

    board[move - 1] = player;
    return true;
}

bool checkWin(const vector<char>& board, char player) {
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }

    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<char>& board) {
    for (char c : board) {
        if (c == EMPTY) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<char> board;
    char currentPlayer = PLAYER_X;

    initializeBoard(board);

    while (true) {
        displayBoard(board);

        if (!makeMove(board, currentPlayer)) {
            continue;
        }

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    char playAgain;
    cout << "Play again? (y/n): ";
    cin >> playAgain;

    if (tolower(playAgain) == 'y') {
        main();
    }

    return 0;
}