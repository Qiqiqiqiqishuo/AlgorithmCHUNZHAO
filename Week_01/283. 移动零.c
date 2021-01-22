void moveZeroes(int* nums, int numsSize){
    int j = 0 ;
    for(int i=0; i<numsSize; i++)
        if(nums[i] != 0) {
            nums[j] = nums[i];
            if(i != j) {
                nums[i] = 0;
            }
            j++;
        }
    return nums;

}