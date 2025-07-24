class Solution {
public:
    int dfs(int node, vector<vector<int>>& list, vector<int>& visited) {
        visited[node] = 1;
        if (list[node].size() == 0)
            return node;
        for (auto it : list[node]) {
            if (visited[it] == 0) {
                return dfs(it, list, visited);
            }
        }
        return -1;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> list(n + 1);
        vector<int> visited(n + 1, 0);
        vector<int> indegree(n + 1, 0);
        for (auto it : trust) {
            int i = it[0];
            int j = it[1];
            list[i].push_back(j);
            indegree[j]++;
        }
        for (int i = 1; i <= n; i++) {
            int ans = dfs(i, list, visited);
            if (ans != -1 && indegree[ans] == n - 1) {
                return ans;
            }
        }
        return -1;
    }
};
