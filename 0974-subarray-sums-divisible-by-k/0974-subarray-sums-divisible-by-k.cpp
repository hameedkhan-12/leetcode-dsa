class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int count = 0;
        int prefixSum = 0;

        for(int num: nums){
            prefixSum += num;
            int remainder = ((prefixSum %k) + k) % k;
            if(mp.count(remainder)){
                count += mp[remainder];
            }
            mp[remainder]++;
        }
        return count;
    }
};