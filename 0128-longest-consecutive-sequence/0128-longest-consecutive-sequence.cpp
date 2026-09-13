class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        for(int num: nums){
            set.insert(num);
        }
        int longest = 0;
        for(int num: set){
            if(!set.count(num-1)){
                int current = num;
                int count = 1;

                while(set.count(current+1)){
                    count++;
                    current++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};