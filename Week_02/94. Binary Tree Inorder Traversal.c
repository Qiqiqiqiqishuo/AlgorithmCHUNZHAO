// 1. 递归解法---------------------------------------------------------------------------------------------------------------------------------------------------------



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root, int* res, int* resSize) {
    if (!root) {
        return ;
    }
    inorder(root->left, res, resSize);
    res[(*resSize)++] = root->val;
    inorder(root->right, res, resSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = (int*) malloc(sizeof(int)*100);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}



// 2. 迭代解法--------------------------------------------------------------------------------------------------------------------------------------------------------



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    struct TreeNode** stack0 = malloc(sizeof(struct TreeNode*) * 100);
    int *res = (int*) malloc(sizeof(int) * 100);
    *returnSize = 0;
    int top = 0;
    while (root != NULL || top > 0) {
        while (root != NULL) {
            stack0[top++] = root;
            root = root->left;
        }
        root = stack0[--top];
        res[(*returnSize)++] = root->val;
        root = root->right;
    }
    return res;

}
