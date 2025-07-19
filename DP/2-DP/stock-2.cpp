//memoized code
class Solution {
public:
    int fun(int index,vector<int>&prices,int buy,vector<vector<int>>&dp){
        if(index==prices.size())return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit = 0;
        if(buy){
            profit+=max(-prices[index]+fun(index+1,prices,0,dp),
                0+fun(index+1,prices,1,dp)
            );
        }
        else{
            profit+=max(prices[index]+fun(index+1,prices,1,dp),
                    0+fun(index+1,prices,0,dp)
            );
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return fun(0,prices,1,dp);
    }
};

// recursive code for it
class Solution {
public:
    int fun(int index,vector<int>&prices,int buy){
        if(index==prices.size())return 0;
        int profit = 0;
        if(buy){
            profit+=max(-prices[index]+fun(index+1,prices,0),
                0+fun(index+1,prices,1)
            );
        }
        else{
            profit+=max(prices[index]+fun(index+1,prices,1),
                    0+fun(index+1,prices,0)
            );
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return fun(0,prices,1);
    }
};
