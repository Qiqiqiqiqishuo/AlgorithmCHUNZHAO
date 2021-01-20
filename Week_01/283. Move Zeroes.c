

void moveZeroes(int* nums, int numsSize){

    int zero_num = 0;
    for(int i = numsSize-1; i>0; i--) {
        if(nums[i] == 0) {
            if(i == numsSize-1) {
                zero_num ++;
                continue;
            }
            for(int j = i; j < numsSize-1; j++) {
                nums[j] = nums[j+1];
                zero_num ++;
            }
        }

    }
    if (zero_num == numsSize) {
        return nums;
    }
    if(nums[0] == 0) {
        for(int l = 0; l<numsSize-1; l++){
            nums[l] = nums[l+1];
        }
        zero_num ++;
    }

    for(int k = numsSize-1; k>=numsSize-zero_num; k--) {
        nums[k] = 0;

    }
    return nums;







  /*  
    int *zero;
    int zero_new_index=0;
    int non_zero_size = numsSize;
    zero = (int*)malloc(sizeof(int) * numsSize);
    for(int i=0; i<numsSize; i++){
        if (nums[i] == 0) {
            zero[zero_new_index] = i;
            zero_new_index ++;

        }
    }
    int zero_number = zero_new_index + 1;
    //获得0的index及数量并储存

    if (zero_number == numsSize) {
        return nums;
    }
    //输入数组元素均为0时，直接返回原数组

    while(zero[zero_number-1] == non_zero_size-1) {
        non_zero_size -= 1;
        zero_number -=1;
    }
    //最后一位数为0时，原数组与存0数组均删除最后一位元素

    
    for(int j=zero_number-1; j>0; j--) {
        for(int k = zero[j-1]; k > zero[j]-1; k++) {
            nums[k-numsSize]


        }
        zero_number-1;



    }
    //输入数组不均为零且最后一位元素值不为0时
    //每两个零之间的元

    for(int k = numsSize ;; ) {

    }

*/

}