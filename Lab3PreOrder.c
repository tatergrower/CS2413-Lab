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
void preOrder(struct TreeNode* root, int *arr, int *returnSize){
    if(root!=NULL){
        arr[(*returnSize)++]=root->val;
        preOrder(root->left, arr, returnSize);
        preOrder(root->right, arr, returnSize);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    preOrder(root, arr, returnSize);
    return arr;
    free(arr);
}
