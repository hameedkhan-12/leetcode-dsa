class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());

        while(min != 0 ){
            int remainder = max % min;
            max = min;
            min = remainder;
        }
        return max;
    }
};