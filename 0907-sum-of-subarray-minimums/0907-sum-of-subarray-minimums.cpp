class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);
        long long sum = 0;
        int M = 1e9+7;

        for(int i = 0; i<n; i++){
            int ls = i - NSL[i];
            int rs = NSR[i] - i;
            long long totalWays = ls * rs;
            long long totalSum = arr[i] * totalWays;
            sum = (sum + totalSum)%M;
        }
        return sum;
    }
    vector<int> getNSL(vector<int> &arr,int n){
        vector<int> NSL(n);
        stack<int> st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                NSL[i] = -1;
            }else{
                NSL[i] = st.top();
            }
            st.push(i);
        }
        return NSL;
    }
    vector<int> getNSR(vector<int> &arr, int n){
        vector<int> NSR(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                NSR[i] = n;
            }else{
                NSR[i] = st.top();
            }
            st.push(i);
        }
        return NSR;
    }
};