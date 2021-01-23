void rotate(int* nums, int numsSize, int k){
    if (k == 0) {
        return nums;
    }
    int *nums_copy = (int *) malloc(sizeof(int) * numsSize);
    for (int i=0; i<numsSize; i++) {
        nums_copy[i] = nums[i];
    }
    for (int j=0; j<numsSize; j++) {
        nums[(j+k)%numsSize] = nums_copy[j];
    }
    return nums;
}