class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int prefixSum = 0;
        int count = 0;
        for(int num: nums){
            prefixSum += num;
            int needed = prefixSum - goal;
            if(mp.count(needed)){
                count += mp[needed];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};