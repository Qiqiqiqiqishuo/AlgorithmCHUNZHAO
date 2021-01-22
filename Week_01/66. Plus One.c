/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for (int i = digitsSize -1; i>=0; i--) {
        if (digits[i] != 9) {
            digits[i] ++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }
    int *res = malloc(sizeof(int) * (digitsSize+1));
    res[0] = 1;
    for(int j=1; j<digitsSize+1; j++) {
        res[j] = 0;
    }
    *returnSize = digitsSize +1;
    return res;
}