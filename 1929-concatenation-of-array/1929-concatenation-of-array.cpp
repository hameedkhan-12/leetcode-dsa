class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = 2 * nums.size();

        vector<int> concatNums(n);
         for (int i = 0; i < n; i++) {
            concatNums[i] = nums[i%nums.size()];
        }
        return concatNums;
    }
};