// recursive solution 
class Solution {
public:
    long long fun(vector<vector<int>> questions, int i) {
        if (i >= questions.size())
            return 0;
        int points = questions[i][0];
        int brain = questions[i][1];
        int pick = points + fun(questions, i + brain + 1);
        int notpick = fun(questions, i + 1);
        return max(pick, notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        return fun(questions, 0);
    }
};
//momoized code
class Solution {
public:
    long long fun(vector<vector<int>>& questions, int i,
                  vector<long long>& dp) {
        if (i >= questions.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        long long points = questions[i][0];
        long long brain = questions[i][1];
        long long pick = points + fun(questions, i + brain + 1, dp);
        long long notpick = fun(questions, i + 1, dp);
        return dp[i] = max(pick, notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return fun(questions, 0, dp);
    }
};
