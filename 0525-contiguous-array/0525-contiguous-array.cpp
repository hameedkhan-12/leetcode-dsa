class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1;

        int prefixSum = 0;
        int maxLen = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0) prefixSum--;
            else prefixSum++;

            if(mp.count(prefixSum)){
                int length = i - mp[prefixSum];
                maxLen = max(maxLen, length);
            }else{
                mp[prefixSum] = i;
            }
        }
        return maxLen;
    }
};