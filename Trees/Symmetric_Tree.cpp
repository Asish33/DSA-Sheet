// same as same tree question but we have to swap left and right pointers when calling for recursion.
// compare same tree solution and symmteric tree solution, then you will get it.
class Solution {
public:
    bool fun(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return fun(p->left, q->right) && fun(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) { return fun(root->left, root->right); }
};
