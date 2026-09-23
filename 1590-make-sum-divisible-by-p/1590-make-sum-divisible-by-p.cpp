class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum % p;
        if (target == 0) {
            return 0;
        }

        unordered_map<int, int> lastIndex;
        lastIndex[0] = -1;

        long long prefixSum = 0;
        int minLen = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int currentRemainder = prefixSum % p;
            int needed =
                (currentRemainder - target + p) % p;

            if (lastIndex.find(needed) != lastIndex.end()) {
                int length = i - lastIndex[needed];
                minLen = min(minLen, length);
            }
            lastIndex[currentRemainder] = i;
        }
        return minLen == nums.size() ? -1 : minLen;
    }
};