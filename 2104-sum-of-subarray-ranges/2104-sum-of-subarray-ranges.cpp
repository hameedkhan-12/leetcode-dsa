class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumOfSubarrayMax(nums);
        long long minSum = sumOfSubarrayMin(nums);

        return maxSum - minSum;
    }
    long long sumOfSubarrayMin(vector<int> & arr){
        int n = arr.size();
        vector<int> NSL(n);
        vector<int> NSR(n);
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
        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }if(st.empty()){
                NSR[i] = n;
            }else{
                NSR[i] = st.top();
            }
            st.push(i);
        }

        long long minSum = 0;
        for(int i = 0; i<n;i++){
            int ls = i - NSL[i];
            int rs = NSR[i] - i;
            long long totalWays = ls * rs;
            long long totalSum = arr[i] * totalWays;
            minSum = minSum + totalSum;
        }

        return minSum;
    }
    long long sumOfSubarrayMax(vector<int> &arr){
        int n = arr.size();
        vector<int> NGL(n);
        vector<int> NGR(n);
        stack<int> st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(st.empty()){
                NGL[i] = -1;
            }else{
                NGL[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(st.empty()){
                NGR[i] = n;
            }else{
                NGR[i] = st.top();
            }
            st.push(i);
        }

        long long maxSum = 0;

        for(int i = 0; i<n; i++){
            int ls = i - NGL[i];
            int rs = NGR[i] - i;
            long long totalWays = ls * rs;
            long long totalSum = arr[i] * totalWays;
            maxSum = maxSum + totalSum;
        }
        return maxSum;
    }
};