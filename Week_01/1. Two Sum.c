/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *res = (int*) malloc(sizeof(int) * 2);
    res[0] = -1;
    for (int i=0; i<numsSize-1; i++) {
        for (int j=i+1; j<numsSize; j++)
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
    }
    *returnSize = 0;
    return 0;

}