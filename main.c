#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // the Tic Tac Toe board

// function to initialize the board with empty spaces
void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// function to print the board to the console
void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
}

// function to check if a player has won the game
char check_win() {
    int i, j;
    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // if no winner is found
    return ' ';
}

// function to get a move from a player
void get_move(int player, int *row, int *col) {
    printf("Player %d, enter your move (row col): ", player);
    scanf("%d %d", row, col);
}

// function to make a move on the board
void make_move(int player, int row, int col) {
    board[row][col] = (player == 1) ? 'X' : 'O';
}

int main() {
    int player = 1; // player 1 starts the game
    int row, col;
    char winner;

    init_board();
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X, Player 2: O\n");
    while (1) {
        print_board();
        get_move(player, &row, &col);
        make_move(player, row, col);
        winner = check_win();
        if (winner != ' ') {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1) ? 2 : 1; // switch players
    }
    print_board();

    return 0;
}