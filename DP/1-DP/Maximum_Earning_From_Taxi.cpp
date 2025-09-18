//recursive solution.

class Solution {
public:
    long long fun(int i, int n, vector<vector<int>>& nums){
        if(i >= n) return 0;

        long long notpick = 0+fun(i + 1, n, nums);
        long long pick = 0;
        long long profit = (long long)(nums[i][1] - nums[i][0] + nums[i][2]);

        int pointer = i + 1;
        while(pointer < n && nums[pointer][0] < nums[i][1]) pointer++;

        pick = profit + fun(pointer, n, nums);

        return max(pick, notpick);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end()); // sorting rides array based on starting point. so that we can apply dp to pick the present passenger or to skip passenger.
        return fun(0, rides.size(), rides);
    }
};

//memoized code


class Solution {
public:
    long long fun(int i, int n, vector<vector<int>>& nums, vector<long long>& dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        
        long long notpick = fun(i + 1, n, nums, dp);

        
        long long profit = (long long)(nums[i][1] - nums[i][0] + nums[i][2]);

        // Binary search for next ride whose start >= current end. using lowerbound here because manual while loop pointer moving is causing tle.
        int pointer = lower_bound(nums.begin() + i + 1, nums.end(), 
                                  vector<int>{nums[i][1], 0, 0}) - nums.begin();

        long long pick = profit + fun(pointer, n, nums, dp);

        return dp[i] = max(pick, notpick);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end()); 
        vector<long long> dp(rides.size() + 1, -1);
        return fun(0, rides.size(), rides, dp);
    }
};

