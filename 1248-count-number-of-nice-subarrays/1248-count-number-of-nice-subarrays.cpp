class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int oddCount = 0;
        mp[oddCount] = 1;

        int count = 0;
        for(int i=0; i<nums.size(); i++){
            oddCount += (nums[i] % 2);

            int needed = oddCount - k;
            if(mp.count(needed)){
                count += mp[needed];
            }
            mp[oddCount]++;
        }
        return count;
    }
};