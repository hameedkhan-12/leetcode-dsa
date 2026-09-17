class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0] = 1;

        int count = 0;
        int prefSum = 0;
        for(int num: nums){
            prefSum += num;
            int needed = prefSum - goal;
            if(mp.count(needed)){
                count += mp[needed];
            }
            mp[prefSum]++;
        }
        return count;
    }
};