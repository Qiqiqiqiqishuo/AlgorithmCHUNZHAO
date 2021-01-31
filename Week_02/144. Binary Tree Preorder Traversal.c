// 1. 递归解法--------------------------------------------------------------------------------------------------------------------
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
void preorder(struct TreeNode* root, int* res, int* resSize) {
    if (!root) {
        return;
    }
    if (root->left || root->right) {
        res[(*resSize)++] = root->val;
        preorder(root->left, res, resSize);
        preorder(root->right, res, resSize);
    } else {
        res[(*resSize)++] = root->val;
        return;
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = (int*) malloc(sizeof(int)*100);
    *returnSize = 0;
    preorder(root, res, returnSize);
    return res;
}



// 2. 迭代解法----------------------------------------------------------------------------------------------------------------------
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
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    struct TreeNode** stack0 = malloc(sizeof(struct TreeNode*) * 100);
    *returnSize = 0;
    int *res = malloc(sizeof(int) * 100);
    int top = 0;
    while (root != NULL || top > 0) {
        while (root != NULL) {
            res[(*returnSize)++] = root->val;
            stack0[top++] = root;
            root = root->left;
        }
        root = stack0[--(top)];
        root = root->right;
        
    }
    return res;
}