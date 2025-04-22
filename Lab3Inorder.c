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
void inOrder(struct TreeNode* root, int* arr, int* returnSize) {
    if (root != NULL) {
        inOrder(root->left, arr, returnSize);
        arr[(*returnSize)++] = root->val;
        // preOrder(root->left, arr, returnSize);
        inOrder(root->right, arr, returnSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    inOrder(root, arr, returnSize);
    return arr;
    free(arr);
}
