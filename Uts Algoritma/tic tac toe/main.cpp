#include <iostream>
using namespace std;

// Fungsi untuk menggambar papan permainan
void drawBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
    cout << endl;
}

// Fungsi untuk memeriksa apakah ada pemenang
char checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Periksa baris
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];

        // Periksa kolom
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Periksa diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;
    char winner = ' ';

    cout << "Permainan Tic-Tac-Toe\n";

    while (true) {
        drawBoard(board);

        // Pemain mengisi kotak
        cout << "Giliran pemain " << currentPlayer << " (baris kolom): ";
        cin >> row >> col;

        // Periksa apakah kotak sudah terisi
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Periksa pemenang
            winner = checkWinner(board);
            if (winner != ' ') {
                drawBoard(board);
                cout << "Pemain " << winner << " menang!\n";
                break;
            }

            // Ganti giliran pemain
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else {
            cout << "Kotak sudah terisi. Coba lagi.\n";
        }
    }

    return 0;
}