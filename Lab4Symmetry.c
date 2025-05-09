
// checks if trees are mirrors images
bool isMirror(struct TreeNode* n1, struct TreeNode* n2) {
    if (n1 == NULL && n2 == NULL) {
        return true;
    }

    if (n1 == NULL || n2 == NULL) {
        return false;
    }

    return (n1->val == n2->val) &&
           isMirror(n1->left, n2->right) &&
           isMirror(n1->right, n2->left);
}

//main function that actually checks symmetry
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

