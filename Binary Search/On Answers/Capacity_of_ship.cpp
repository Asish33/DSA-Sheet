class Solution {
public:
     bool fun(vector<int>& weights, int days, int mid) {
        int dayCount = 1;
        int currentLoad = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > mid) return false; 
            if (currentLoad + weights[i] <= mid) {
                currentLoad += weights[i];
            } else {
                dayCount++;
                currentLoad = weights[i];
            }
        }
        return dayCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1,high = 0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(fun(weights,days,mid)){
                ans = mid;
                high = mid-1; // we found the answer, and we are trying other smaller values so we will get minimum value as answer.
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
