class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> unique;
        for(int num: nums){
            unique.insert(num);
        }
        int i = 0;
        for(int val : unique){
            nums[i++] = val;
        }
        return unique.size();
    }
};