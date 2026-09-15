class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int countZeroes = 0;
        int prodWithoutZeroes = 1;
        for(int num: nums){
            if(num == 0){
                countZeroes++;
            }else{
                prodWithoutZeroes *= num;
            }
        }

        for(int i = 0; i<nums.size(); i++){
            int num = nums[i];

            if(num != 0 && countZeroes > 0){
                result[i] = 0;
            }else if(countZeroes >1){
                result[i] = 0;
            }else if(num == 0 && countZeroes == 1){
                result[i] = prodWithoutZeroes;
            }else{
                result[i] = prodWithoutZeroes / num;
            }
        }
        return result;
    }
};