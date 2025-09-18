class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a,
                        const pair<int, int>& b) const {
            if (a.first == b.first)
                return a.second < b.second; // larger second comes first
            return a.first < b.first;       // larger first comes first
        }
    };

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int left = 0;
        int right = left + k - 1;
        vector<int> ans;

        while (right < nums.size()) {
            map<int, int> mpp;
            for (int i = left; i <= right; i++) {
                mpp[nums[i]]++; 
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
            for (auto it : mpp) {
                pq.push({it.second, it.first});
            }

            int tempans = 0;
            int count = 0;
            while (count < x && !pq.empty()) {
                int key = pq.top().second;
                int freq = pq.top().first;
                tempans += key * freq;
                pq.pop(); 
                count++;
            }

            ans.push_back(tempans);
            left++;
            right++;
        }

        return ans;
    }
};
