//recursive solution 
// classic pick and not_pick
class Solution {
public:
    int fun(vector<int>& coins, int target, int i) {
        if (target == 0)
            return 0;    // if target is 0 then we don't have to pick any coins. so we will return 0.
        if (i == coins.size())
            return 1e9;  // if we hit out of bounds case without having target = 0 that means we can't form target with coins. then we will return 1e9 symbolically saying it is impossible.
                        // generally we return 0 when it is not possible. but here as question mentioned we have to return min coins we will return 1e9. if we return 0 then it will be minimum but we are using 
                        // it for not possible case, which leads to wrong result.
        int notpick = fun(coins, target, i + 1);
        int pick = 1e9;   // here instead of 0 we are using 1e9 as it is mentioned in question to use minimum coins. if we use 0 it will be minimum.
        if (target >= coins[i]) {
            pick = 1 + fun(coins, target - coins[i], i);
        }

        return min(notpick, pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        int ans = fun(coins, amount, 0);
        return (ans >= 1e9 ? -1 : ans);
    }
};

//memoization solution

class Solution {
public:
    int fun(vector<int>&coins,int target,int i, vector<vector<int>>& dp){
        if(target==0) return 0;
        if(i==coins.size()) return 1e9;

        if(dp[i][target] != -1) return dp[i][target];

        int notpick = fun(coins,target,i+1,dp);
        int pick = 1e9;
        if(target>=coins[i]){
            pick = 1 + fun(coins,target-coins[i],i,dp);
        }
        
        return dp[i][target] = min(notpick,pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1)); // as amount value goes from 0 to amount value we will have amount+1 values. including zero will increase entry.

        int ans = fun(coins,amount,0,dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};
