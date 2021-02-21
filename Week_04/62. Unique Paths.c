//---------------------------------------------------------------------
// 1. 组合  O(min(m, n)) O(1)
//  向下移动m-1次，向右移动n-1次
//  待补充
int uniquePaths(int m, int n) {
    long long res = 1;
    if (m > n) {
        int temp = n;
        n = m;
        m = temp;
    }
    for (int x = n, y = 1; y < m; ++x, ++y) {
        res = res * x / y;
    }
    return res;
}



//-----------------------------------------------------------------------
// 2. 动态规划 O(mn) O(mn)
//  待写一维数组解
int uniquePaths(int m, int n) {
    int f[m][n];
    for (int i = 0; i < m; ++i) {
        f[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        f[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
}