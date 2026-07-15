#include <stdio.h>
#define N 4


void printSolution(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}


int isSafe(char board[N][N], int row, int col) {
    int i, j;

    
    for (i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return 0;

    
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return 0;

   
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j] == 'Q')
            return 0;
    return 1;
}


int solveNQUtil(char board[N][N], int col) {

    
    if (col >= N)
        return 1;

    
    for (int i = 0; i < N; i++) {

        if (isSafe(board, i, col)) {

            board[i][col] = 'Q';

            
            if (solveNQUtil(board, col + 1))
                return 1;

            
            board[i][col] = '-';
        }
    }
    return 0;
}


int main() {

    char board[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '-';

    if (solveNQUtil(board, 0) == 0) {
        printf("Solution does not exist\n");
    } else {
        printf("Solution for %d Queens problem:\n", N);
        printSolution(board);
    }
    return 0;
}
