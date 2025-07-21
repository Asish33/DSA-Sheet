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
        return fun(p->left, q->left) && fun(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) { return fun(p, q); }
};
