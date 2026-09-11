class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Empty prefix
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {

            prefixSum += num;

            int needed = prefixSum - k;

            if (freq.find(needed) != freq.end()) {
                count += freq[needed];
            }

            freq[prefixSum]++;
        }

        return count;
    }
};