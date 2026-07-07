class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long windowSum = 0;
        long long ans = 0;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];
            freq[nums[right]]++;

            if (right - left + 1 > k) {
                windowSum -= nums[left];
                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            if (right - left + 1 == k) {
                if (freq.size() == k) {
                    ans = max(ans, windowSum);
                }
            }
        }
        return ans;
    }
};