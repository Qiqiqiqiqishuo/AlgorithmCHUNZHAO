#define MIN(a,b,c) ((a)<(b)?( (a)<(c)?(a):(c) ):( (b)<(c)?(b):(c) ))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0)    return 0;
    int j, k, ms = matrix[0][0];
    for (j=0; j<matrixSize; j++)
        for (k=0; k<matrixColSize[j]; k++) {
            if (matrix[j][k]=='1' && j>0 && k>0)
                matrix[j][k] = MIN(matrix[j-1][k],matrix[j][k-1],matrix[j-1][k-1]) + 1;
            if (matrix[j][k] > ms)
                ms = matrix[j][k];
        }
    return (ms-'0')*(ms-'0');
}