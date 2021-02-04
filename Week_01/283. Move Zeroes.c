//---------------------------------------------------------------------------------------------------------------------------------------------
// 1. 双指针之不讲武德数零法 O(n) O(1)
// 万万不要用此法，2.4日仍未理解透彻，遂不讲武德偷鸡
void moveZeroes(int* nums, int numsSize){
    int ins_index = 0;
    int count = 0;
    for (int i=0; i<numsSize; i++) {
        if (0 == nums[i]) {
            count++;
        } else {
            nums[ins_index++] = nums[i];
        }
    }
    for (int j=numsSize-1; j>numsSize-1-count; j--) {
        nums[j] = 0;
    }
    return nums;

}



//---------------------------------------------------------------------------------------------------------------------------------------------
// 2. 双指针法 O(n) O(1)
void moveZeroes(int* nums, int numsSize){
    int ins_index = 0;
    int zero_index = numsSize-1;
    for (int i=0; i<numsSize; i++) {
        if (0 != nums[i]) {
            nums[ins_index] = nums[i];
            if (i != ins_index) {
                nums[i] = 0;
            }
            ins_index++;
        }
    }
    return nums;

}