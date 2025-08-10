class Solution {
public:
    int helper(vector<int>& a) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            int minIndex = i;
            for (int j = i + 1; j < a.size(); j++) {
                if (a[j] < a[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(a[i], a[minIndex]);
                count++;
            }
        }
        return count;
    }

    int minimumOperations(TreeNode* root) {
        int ans = 0;
        // bfs
        // queue create array lo all items push tharuvatha aa array ni helper
        // fun ki ichi ans increase cheyali.
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();
                level.push_back(top->val);
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            ans += helper(level);
        }
        return ans;
    }
};
