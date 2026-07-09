class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long divisor = calcDivisor(nums, mid);

            if (divisor <= threshold) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int calcDivisor(vector<int>& nums, int midVal) {
        long long divisor = 0;
        for (double num : nums) {
            divisor += ceil(num / midVal);
        }
        return divisor;
    }
};