class Solution {
public:
    bool willwork(vector<int>&bloomDay,int m , int k ,int day){
        int boquets=0,flowers=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                flowers++;
                if(flowers==k){
                    boquets++;
                    flowers=0;
                }
            }else{
                flowers=0;
            }
        }
        return boquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end()),high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(willwork(bloomDay,m,k,mid)){
                ans=mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
