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

//optimal solution using stack with previous greater element.
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index = -1;

    StockSpanner() {
        while (!st.empty())
            st.pop();
    }

    int next(int price) {
        index++;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int ans = st.empty() ? index + 1 : index - st.top().second;
        st.push({price, index});
        return ans;
    }
};

