//--------------------------------------------------------------------------
// 1. 不讲武德之乌龟爬
//  从右上角往下爬到所在行，再往左爬
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (!matrixSize || !(*matrixColSize)) return false;
    int row = 0, column = (*matrixColSize) - 1, mid_row;
    while (row < matrixSize && column >= 0) {
        if (matrix[row][column] == target) return true;
        if (matrix[row][column] < target) row++;
        else column--;
    }
    return false;
}



//--------------------------------------------------------------------------
// 2. 二分查找 O(logn) O(1)
//  **尚未完全理解且待优化**
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (!matrixSize || !(*matrixColSize)) return false;  // 特判
    int left = 0, right = matrixSize - 1, mid_row;  // 行二分查找
    bool refresh = false;  // 初始化为行二分是否刷新mid_row
    while (left <= right) {
        mid_row = left + ((right - left) >> 1);
        if (matrix[mid_row][0] > target) {
            right = mid_row - 1;  // 向上找
            refresh = true;  // 刷新
        }
        if (matrix[mid_row][(*matrixColSize)-1] < target) {
            left = mid_row + 1;  // 向下
            refresh = true;  // 刷新
        }
        if (!refresh) {  // 1.没刷新证明找到特定行
            int L = 0, R = (*matrixColSize) - 1, mid;  // 列二分操作
            while (L <= R) {
                mid = L + ((R - L) >> 1);
                if (matrix[mid_row][mid] == target) return true;
                else if (matrix[mid_row][mid] > target) R = mid - 1;
                else L = mid + 1;
            }
            break;  // 只要进来了，不满足就一定没找到
            // return false;
        }else refresh = false;  // 否则刷新为false
    }
    return false;  // 二分行找不到错误，返回假
}