class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int totalSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> uniqueEle;
            for (int j = i; j < nums.size(); j++) {
                uniqueEle.insert(nums[j]); 

                int count = uniqueEle.size();
                totalSum += count * count;
            }
        }

        return totalSum;
    }
};