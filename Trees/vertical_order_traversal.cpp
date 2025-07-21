
class Solution {
public:
    void dfs(map<int, map<int, multiset<int>>>& nodes, TreeNode* root, int col,
             int row) {
        if (root == NULL)
            return;
        nodes[col][row].insert(root->val);
        dfs(nodes, root->left, col - 1, row + 1);
        dfs(nodes, root->right, col + 1, row + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        dfs(nodes, root, 0, 0);
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
