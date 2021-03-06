//------------------------------------------------------------------------------------------------------------------------------
// 1. DFS
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
const int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int n, m;

void dfs(char** board, int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        int tx = x + dir_x[i];
        int ty = y + dir_y[i];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
            continue;
        }
        cnt += board[tx][ty] == 'M';
    }
    if (cnt > 0) {
        board[x][y] = cnt + '0';
    } else {
        board[x][y] = 'B';
        for (int i = 0; i < 8; ++i) {
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || board[tx][ty] != 'E') {
                continue;
            }
            dfs(board, tx, ty);
        }
    }
}

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
    n = boardSize, m = boardColSize[0];
    int x = click[0], y = click[1];
    if (board[x][y] == 'M') {
        board[x][y] = 'X';
    } else {
        dfs(board, x, y);
    }
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
    }
    return board;
}