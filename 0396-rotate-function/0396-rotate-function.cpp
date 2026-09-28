class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long F = 0;
        long long sum = 0;

        for(int i = 0; i<n; i++){
            sum += nums[i];
            F += i * nums[i];
        }
        long long result = F;
        for(int k = 0; k<n; k++){
            long long newF = F + sum - n*nums[n-1-k];
            result = max(result, newF);

            F = newF;
        }
        return result;
    }
};