//----------------------------------------------------------------------------------------------------------------------------------
// 1. 回溯1
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int solutionsSize;

char** generateBoard(int* queens, int n) {
    char** board = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++) board[i][j] = '.';
        board[i][queens[i]] = 'Q', board[i][n] = 0;
    }
    return board;
}

void backtrack(char*** solutions, int* queens, int n, int row, int* columns, int* diagonals1, int* diagonals2) {
    if (row == n) {
        char** board = generateBoard(queens, n);
        solutions[solutionsSize++] = board;
    } else {
        for (int i = 0; i < n; i++) {
            if (columns[i]) {
                continue;
            }
            int diagonal1 = row - i + n - 1;
            if (diagonals1[diagonal1]) {
                continue;
            }
            int diagonal2 = row + i;
            if (diagonals2[diagonal2]) {
                continue;
            }
            queens[row] = i;
            columns[i] = true;
            diagonals1[diagonal1] = true;
            diagonals2[diagonal2] = true;
            backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
            queens[row] = -1;
            columns[i] = false;
            diagonals1[diagonal1] = false;
            diagonals2[diagonal2] = false;
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char*** solutions = malloc(sizeof(char**) * 501);
    solutionsSize = 0;
    int queens[n];
    int columns[n];
    int diagonals1[n + n];
    int diagonals2[n + n];
    memset(queens, -1, sizeof(queens));
    memset(columns, 0, sizeof(columns));
    memset(diagonals1, 0, sizeof(diagonals1));
    memset(diagonals2, 0, sizeof(diagonals2));
    backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
    *returnSize = solutionsSize;
    *returnColumnSizes = malloc(sizeof(int*) * solutionsSize);
    for (int i = 0; i < solutionsSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return solutions;
} 



//--------------------------------------------------------------------------------------------------------------------------------------------
// 2. 回溯2-位运算
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int solutionsSize;

char** generateBoard(int* queens, int n) {
    char** board = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++) board[i][j] = '.';
        board[i][queens[i]] = 'Q', board[i][n] = 0;
    }
    return board;
}

void solve(char*** solutions, int* queens, int n, int row, int columns, int diagonals1, int diagonals2) {
    if (row == n) {
        char** board = generateBoard(queens, n);
        solutions[solutionsSize++] = board;
    } else {
        int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
        while (availablePositions != 0) {
            int position = availablePositions & (-availablePositions);
            availablePositions = availablePositions & (availablePositions - 1);
            int column = __builtin_ctz(position);
            queens[row] = column;
            solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
            queens[row] = -1;
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char*** solutions = malloc(sizeof(char**) * 501);
    solutionsSize = 0;
    int queens[n];
    memset(queens, -1, sizeof(queens));
    solve(solutions, queens, n, 0, 0, 0, 0);
    *returnSize = solutionsSize;
    *returnColumnSizes = malloc(sizeof(int*) * solutionsSize);
    for (int i = 0; i < solutionsSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return solutions;
}