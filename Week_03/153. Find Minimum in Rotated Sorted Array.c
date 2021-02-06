//-------------------------------------------------------------------------
// 1. 不讲武德之暴力遍历 O(n) O(1)
//  阅后即焚，此法免提
int findMin(int* nums, int numsSize){
    for (int i=0; i<numsSize; i++)
        nums[0] = nums[i] < nums[0] ? nums[i] : nums[0];
    return nums[0];
}



//-------------------------------------------------------------------------
// 2. 二分查找 O(logn) O(1)
int findMin(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])    left = mid + 1;
        else    right = mid;
    } 
    return nums[left];
}