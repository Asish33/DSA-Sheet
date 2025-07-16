class Solution {
public:
    int celing(int a, int b) { 
        return (a + b - 1) / b; // this returns celing of a division.
    } // celing(2,1)= (2+1-1)/1=2. 
      // celing(3,2) should give us 2. (3+2-1)/2=4/2=2.

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += celing(piles[i], mid);
            }
            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
