/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXSIZE 10000

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    int** res = (int**)malloc(sizeof(int*) * MAXSIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAXSIZE);
    struct Node* queue[MAXSIZE];
    int front = -1, rear = -1;
    queue[++rear] = root;
    while (front != rear) {   
        int num = (rear - front)% MAXSIZE;
        (*returnColumnSizes)[*returnSize] = num;
        res[*returnSize] = (int*)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++) {
            struct Node* p = queue[++front];
            res[*returnSize][i] = p -> val;
            for (int j = 0; j < p -> numChildren; j++) {   
                rear = (rear + 1) % MAXSIZE;
                queue[rear] = p -> children[j];
            }
        }
        (*returnSize)++;
    }
    return res;
}