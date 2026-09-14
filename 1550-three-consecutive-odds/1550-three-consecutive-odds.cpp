class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        int maxCount = 0;

        for (int num : arr) {
            if (num % 2 == 1) {
                count++;
            } else {
                count = 0;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount >=3;
    }
};