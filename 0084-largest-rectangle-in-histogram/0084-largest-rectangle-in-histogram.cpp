class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse(heights.size());
        vector<int> pse(heights.size());
        nse = calcNSE(heights);
        pse = calcPSE(heights);
        int maxArea = INT_MIN;
        for(int i = 0; i<heights.size(); i++){
            int area = heights[i] * (nse[i] - pse[i] -1);
            if(area > maxArea){
                maxArea = area;
            }
        }
        return maxArea;
    }
    vector<int> calcNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> calcPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i <n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
};