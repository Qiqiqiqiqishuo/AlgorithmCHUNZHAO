学习笔记

**使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方。同学们可以将自己的思路、代码写在学习总结中。**

1.读题：升序数组旋转得到此数组

2.二分查找:

```c
int low = 0, high = numsSize - 1;	//low为左索引，high为右索引
int mid = (low + high) / 2;	//mid为中间索引
if (nums[low] < nums[mid]) {
    low = mid;
    mid = (low + high) / 2;
} else {
    
}
if (nums[high] > nums[mid]) {
    high = mid;
    mid = (low + high) / 2;
} else {
    
}
    //low小于或high大于mid,则这部分仍为升序，与mid交换值继续查找
```



