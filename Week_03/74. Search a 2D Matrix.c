//---------------------------------------------------------------------
// 1. 乌龟爬
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (!matrixSize || !(*matrixColSize)) return false;
    int row = 0, column = (*matrixColSize) - 1, mid_row;
    while (row < matrixSize && column >= 0) {
        if (matrix[row][column] == target) return true;
        else if (matrix[row][column] > target) column--;
        else row++;
    }
    return false;
}