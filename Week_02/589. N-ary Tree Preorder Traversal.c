/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void pre(struct Node* root, int* res, int* returnSize) {
    for (int i=0; i<root->numChildren; i++) {
        res[(*returnSize)++] = root->children[i]->val; 
        pre(root->children[i], res, returnSize);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    
    int *res = (int*) malloc(sizeof(int) * 12345);
    *returnSize = 0;
    
    if (!root || root == NULL) {
        return res;
    }
    res[(*returnSize)++] = root->val;
    pre(root, res, returnSize);

    return res;
}