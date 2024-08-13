#include <iostream>
#include <tuple>
using namespace std;

bool gameOver;
char board[3][3];
char player;

void init() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) board[i][j] = '_';
    }

    gameOver = false;
    player = 'X';
}

void draw_board(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 2) cout << ' ';
            else cout << '_';
            if (board[i][j] != '_') cout << board[i][j];
            else cout << ' ';
            if (i == 2) cout << ' ';
            else cout << '_';
            if (j != 2) cout << '|';
        }
        cout << '\n';
    }
}

bool check_tie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') return false;
        }
    }

    return true;
}

bool check_winner(int row, int col, char player) {
    if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
        cout << player << " wins!";
        return true;
    }

    if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
        cout << player << " wins!";
        return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == player) {
        cout << player << " wins";
        return true;
    }

    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] == player) {
        cout << player << " wins";
        return true;
    }

    return false;
}

tuple <int, int> input() {
    int row, col;
    cout << "Enter the number of the row: ";
    while (!(cin >> row) || row > 3 || row < 1) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nInvalid play; Try again;\nEnter the number of the row: ";
    }

    cout << "\nEnter the number of the collumn: ";
    while (!(cin >> col) || col > 3 || col < 1) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid play; Try again;\nEnter the number of the collumn: ";
    }
    return {row, col};
}

void play() {
    while (!gameOver) {
        auto [row, col] = input();
        while (board[row-1][col-1] != '_') {
            cout << "\nInvalid play; Try again.\n";
            auto [r, c] = input();
            row = r;
            col = c;
        }

        board[row-1][col-1] = player;
        draw_board();

        if (check_winner(row-1, col-1, player)) {
            gameOver = true;
        }

        else if (check_tie()) {
            gameOver = true;
            cout << "It was a tie!";
        }

        else {
            if (player == 'X') player = 'O';
            else player = 'X';
        }
    }
}

int main() {
    init();
    draw_board();
    play();

    return 0;
}