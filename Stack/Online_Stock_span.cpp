//brute force approach
class StockSpanner {
public:
    vector<int> store;
    StockSpanner() {}

    int next(int price) {
        store.push_back(price);
        int n = store.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (store[i] <= price) {
                ans++;
            } else {
                return ans;
            }
        }
        return ans;
    }
};
