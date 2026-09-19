class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for(int num: nums){
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k;
            
            count += freq[remainder];
            freq[remainder]++;
        }
        return count;
    }
};