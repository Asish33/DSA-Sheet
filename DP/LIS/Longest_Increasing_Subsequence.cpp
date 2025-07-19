class Solution {
public:
    int fun(int i , int prev ,  vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int length = fun(i+1,prev,nums,dp);
        if(prev==-1 || nums[prev]<nums[i]){
            length = max(length,1+fun(i+1,i,nums,dp));
        }
        return dp[i][prev+1]=length;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(0,-1,nums,dp);
    }
};
