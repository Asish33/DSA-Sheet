class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    bool fun(TreeNode* root) {
        if (root == NULL)
            return true;
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1)
            return false;
        return fun(root->left) && fun(root->right);
    }
    bool isBalanced(TreeNode* root) { return fun(root); }
};
