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
    if (root->left != NULL || root->right != NULL) {
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