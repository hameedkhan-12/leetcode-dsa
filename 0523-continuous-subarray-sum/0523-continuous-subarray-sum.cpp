class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefixSum = 0;
        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int remainder = prefixSum % k;

            if(mp.count(remainder)){
                if(i-mp[remainder] >= 2) return true;
            }else{
                mp[remainder] = i;
            }
        }
        return false;
    }
};