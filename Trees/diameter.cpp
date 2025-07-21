// we are using two functions here. one for getting the answer and another for returning the height of the subtree. time complexity= n*n = N*2.
class Solution {
public:
    int depth(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    int fun(TreeNode* root){
        if(root==NULL)return 0;
        int roots=depth(root->left)+depth(root->right);
        int lefts = fun(root->left);
        int rights = fun(root->right);
        return max({roots,lefts,rights});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return fun(root);
    }
};

// now to optimise this one the idea is to merge those two functions into one, so that we can reduce time complexity to O(N).
//using maxi variable to simulate the fun above and merging that into height function.
class Solution {
public:
    int fun(TreeNode* root, int &maxi) {
        if (root == NULL)
            return 0;

        int left = fun(root->left, maxi);
        int right = fun(root->right, maxi);

        maxi = max(maxi, left + right);

        return 1 + max(left, right);  
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        fun(root, maxi);
        return maxi;
    }
};
