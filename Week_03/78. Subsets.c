/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int* nums, int numsSize, int **res, int* returnSize, int** returnColumnSizes, int * str, int depth, int startindex){
    res[*returnSize] = (int *)malloc(depth*sizeof(int));
    memcpy(res[*returnSize],str,depth*sizeof(int));
    (*returnColumnSizes)[*returnSize] = depth;
    (*returnSize)++;
    for(int i=startindex;i<numsSize;i++){
        str[depth] = nums[i];
        dfs(nums,numsSize,res,returnSize,returnColumnSizes,str,depth+1,i+1);
    }
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int ** res = (int **)malloc(2000*sizeof(int *));
    int * str = (int *)malloc(numsSize*sizeof(int));
    *returnColumnSizes = (int *)calloc(2000,sizeof(int));
    dfs(nums,numsSize,res,returnSize,returnColumnSizes,str,0,0);
    return res;

}