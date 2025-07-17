//recursive solution
class Solution {
public:
    int fun(vector<int>&nums, int i){
        if(i<0)return 0;
        if(i==0)return nums[0];
        int pick = nums[i]+fun(nums,i-2);
        int notpick = fun(nums,i-1);
        return max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        return fun(nums,nums.size()-1);
    }
};

//optimised memo solution here
