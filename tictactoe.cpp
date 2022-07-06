#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>

using namespace std;

vector<vector<char>> initialize(int size) {
    vector<vector<char>> board(size, vector<char>(size));

    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + char(count++);
        }
    }
    return board;
}

void printBoard(vector<vector<char>> board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(2) << board[i][j] << " | ";
        }
        cout << endl;
    }
}

vector<vector<char>> promptMove(char player, vector<vector<char>> board) {
    char choice;
    bool valid = false;

    while (!valid) {
        cout << "Enter a proper move: ";
        cin >> choice;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == choice) {
                    board[i][j] = player;
                    return board;
                }
            }
        }
    }
}

vector<vector<char>> promptAI(char player, vector<vector<char>> board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((board[i][j] != 'O') && (board[i][j] != 'X')) {
                board[i][j] = player;
                return board;
            }
        }
    }
}

bool checkWin(vector<vector<char>> board) {
    int countXh = 0, countXv = 0, countXd = 0, countXdd = 0;
    int countOh = 0, countOv = 0, countOd = 0, countOdd = 0;
    bool win = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                countXh++;
            }
            else if (board[i][j] == 'O') {
                countOh++;
            }
            if (board[j][i] == 'X') {
                countXv++;
            }
            else if (board[j][i] == 'O') {
                countOv++;
            }
        }
        countXh == 3 ? win = true : countXh = 0;
        countOh == 3 ? win = true : countOh = 0;
        countXv == 3 ? win = true : countXv = 0;
        countOv == 3 ? win = true : countOv = 0;
    }


    for (int i = 0, j = 2; i < 3; i++, j--) {
        if (board[i][i] == 'X') {
            countXd++;
        }
        else if (board[i][i] == 'O') {
            countOd++;
        }

        if (board[i][j] == 'X' ) {
            countXdd++;
        }
        else if (board[i][j] == 'O') {
            countOdd++;
        }
        if (countXd == 3 || countXdd == 3) {
            return win = true;
        }
        else if (countOd == 3 || countOdd == 3) {
            return win = true;
        }
    }

    return win;
}

int main()
{
    vector<vector<char>> board = initialize(3);

    //char player1 = 'X', player2 = 'O';
    char players[] = { 'X', 'O' };
    int currentPlayer = 0;
    bool win = false;

    //printBoard(board);
    //promptMove(player1, board);
    
    int count = 0;
    while (!win) {
        printBoard(board);
        board = promptMove(players[0], board);
        win = checkWin(board);
        if (win) { break; }
        else { currentPlayer = 1; };
        board = promptAI(players[1], board);
        if (win) { break; }
        else { currentPlayer = 0; }
        win = checkWin(board);
        count++;
    }

    printBoard(board);
    cout << "Player " << players[currentPlayer] << " wins!" << endl;
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
