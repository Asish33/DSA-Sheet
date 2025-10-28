//recursive solution
class Solution {
public:
    int fun(vector<int>&nums, int i){
        if(i<0)return 0;
        if(i==0)return nums[0];
        int pick = nums[i] + fun(nums,i-2);
        int notpick = fun(nums,i-1);
        return max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        return fun(nums,nums.size()-1);
    }
};

//optimised memo solution here
class Solution {
public:
    int fun(vector<int>&nums, int i,vector<int>&dp){
        if(i<0)return 0;
        if(i==0)return nums[0];
        if(dp[i]!=-1)return dp[i];
        int pick = nums[i]+fun(nums,i-2,dp);
        int notpick = fun(nums,i-1,dp);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return fun(nums,nums.size()-1,dp);
    }
};
