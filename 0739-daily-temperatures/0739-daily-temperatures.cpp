class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ngi(n);

        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (st.empty()) {
                ngi[i] = 0;
            } else {
                ngi[i] = st.top() - i;
            }
            st.push(i);
        }
        return ngi;
    }
};