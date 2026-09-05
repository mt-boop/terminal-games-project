#include <iostream>

void drawboard(char board[3][3]) {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  -+-+-\n";
    }
}

// 1. Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// 2. Function to check if the board is full (Draw)
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int r, c;
    char currentPlayer = 'X';
    bool gameOver = false;

    // 3. Main game loop
    while (!gameOver) {
        drawboard(board);
        
        std::cout << "Player " << currentPlayer << ", enter row (0-2) and col (0-2): ";
        std::cin >> r >> c;

        // Input validation
        if (r < 0 || r > 2 || c < 0 || c > 2 || board[r][c] != ' ') {
            std::cout << "Invalid move! Try again.\n\n";
            continue; // Re-prompt without switching turns
        }

        // Place the move
        board[r][c] = currentPlayer;

        // Check for Win
        if (checkWin(board, currentPlayer)) {
            drawboard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } 
        // Check for Draw
        else if (checkDraw(board)) {
            drawboard(board);
            std::cout << "It's a draw!\n";
            gameOver = true;
        } 
        // Toggle player if game continues
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}