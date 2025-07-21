//simple bfs with alternate reversal.
// we use flag here to check the current level of traversal. In alternate levels we reverse the array and push it back into the ans. we toggle flag at each level so that we can reverse the array alternatively.
class Solution {
public:
    void bfs(vector<vector<int>>& ans, TreeNode* root) {
        if (root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (!flag) {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            flag = !flag;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(ans, root);
        return ans;
    }
};
