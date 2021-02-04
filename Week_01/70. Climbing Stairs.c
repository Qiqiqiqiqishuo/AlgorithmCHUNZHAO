//--------------------------------------------------------------------
// 1. 迭代 O(n) O(1)
int climbStairs(int n){
    if (1 == n) return 1;
    if (2 == n) return 2;
    int f1 = 1;
    int f2 = 2;
    int res;
    for (int i=3; i<=n; i++) {
        res = f2 + f1;
        f1 = f2;
        f2 = res;
    }
    return res;
}