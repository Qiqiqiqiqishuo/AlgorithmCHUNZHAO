//---------------------------------------------------------------------------------------------------------------------
// 1. 排序后取中间数-qsort
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    return nums[numsSize/2];
    
}



//--------------------------------------------------------------------------------------------------------------------
// 2. 排序后取中间数-手撸烂快排，时间超限，挖个坑，读读标准库。
void quicksort (int *nums, int left, int right) {
    int i, j, t, temp;
    if (left > right)   return;
    temp = nums[left];
    i = left;
    j = right;
    while (i != j) {
        while (nums[j] >= temp && i<j)  j--;
        while (nums[i] <= temp && i<j)  i++;
        if (i < j) {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
    nums[left] = nums[i];
    nums[i] = temp;
    quicksort(nums, left, i-1);
    quicksort(nums, i+1, right);
    return;
}

int majorityElement(int* nums, int numsSize){
    quicksort(nums, 0, numsSize-1);
    return nums[numsSize/2];
        
}



//------------------------------------------------------------------------------------------------------------------
// 3. 投票法
int majorityElement(int* nums, int numsSize){
    int major = nums[0];
    int count = 1;
    for (int cur=1; cur<numsSize; cur++) {
        major == nums[cur] ? count++ : count--;
        if (count == 0) {
            major = nums[cur];
            count =1;
        }
    }
    return major;
}