// follows monotonic stack 
// that means it is related to something like next greater, next smaller, previous greater and previous smaller.
class Solution {
public:
    vector<int> nse(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, n); // all are intialized to n because if it has no next smaller element we store n value in it. 
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty())
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> pse(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, -1); // all are initalzed to -1 because if no previous smaller element is present then we will store -1 in that case.
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty())
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmaller = nse(heights);
        vector<int> prevSmaller = pse(heights);
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int left_span = (i - prevSmaller[i]) * heights[i];
            int right_span = (nextSmaller[i] - i) * heights[i];
            int totalAns = left_span + right_span - heights[i]; // as we are considering height[i] two times, in left_span and in right_span, we remove height[i] to make it correct.
            ans = max(ans, totalAns);
        }
        return ans;
    }
};
