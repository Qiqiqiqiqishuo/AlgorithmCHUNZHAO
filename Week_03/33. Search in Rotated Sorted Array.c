//---------------------------------------------------------------------------
// 1. 不讲武德之暴力遍历 O(n) O(1)
//  阅后即焚，此法免提
int search(int* nums, int numsSize, int target){
    for (int i=0; i<numsSize; i++)
        if (target == nums[i])  return i;
    return -1;
}



//--------------------------------------------------------------------------
// 2. 减治二分 O(logn) O(1)
//  **尚未完全理解**
int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (target == nums[mid])    return mid;
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid -1;
            } else {
                left = mid +1;
            }
        } else if (target > nums[mid] && target <= nums[right]) {
            left = mid + 1;
        } else {
                right = mid - 1;
        }
    }
    return -1;
}