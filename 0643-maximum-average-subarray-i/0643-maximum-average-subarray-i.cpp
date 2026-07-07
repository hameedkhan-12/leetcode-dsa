class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        double windowSum = 0;
        double ans = -1e9;

        for(int right = 0; right < nums.size(); right++){
            windowSum += nums[right];
            if(right - left + 1 > k){
                windowSum -= nums[left];
                left++;
            }
            if(right - left + 1 == k){
                ans = max(ans, windowSum);
            }
        }
        return ans/k;
    }
};