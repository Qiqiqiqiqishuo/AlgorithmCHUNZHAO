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
void post(struct Node* root, int* res, int* returnSize) {
    for (int i=0; i<root->numChildren; i++) {
        post(root->children[i], res, returnSize);
        res[(*returnSize)++] = root->children[i]->val;
    }
}

int* postorder(struct Node* root, int* returnSize) {
    int *res = (int*) malloc(sizeof(int) * 12345);
    *returnSize = 0;
    if (!root || root == NULL) {
        return res;
    }
    post(root, res, returnSize);
    res[(*returnSize)++] = root->val;
    return res;
}