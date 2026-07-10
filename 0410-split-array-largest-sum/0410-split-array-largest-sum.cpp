class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = 0;
        for (int i = 0; i < nums.size(); i++) {
            right += nums[i];
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (calcSubarraysSumPossible(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int calcSubarraysSumPossible(vector<int>& nums, int maxSum, int k) {
        long long sum = 0;
        int groups = 1;
        for (int num : nums) {
            if (sum + num <= maxSum) {
                sum += num;
            } else {
                groups++;
                sum = num;
            }
        }
        return groups <= k;
    }
};