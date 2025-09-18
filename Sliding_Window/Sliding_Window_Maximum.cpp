class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> s;
        for (int i = 0; i < k; i++) {
            s.insert(nums[i]);
        }
        ans.push_back(*s.rbegin());
        int i = 0, j = k - 1;
        while (j < nums.size()) {
            auto it = s.find(nums[i]); // here we can use erase function but if we use it it removes
            if (it != s.end()) {       // all the occurances of that element. so we are using find approach so that it removes only one occurance.
                s.erase(it);           // that occurance can be any one but here we are removing first one.
            }
            i++, j++;
            if (j >= nums.size())
                break;
            s.insert(nums[j]);
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};
