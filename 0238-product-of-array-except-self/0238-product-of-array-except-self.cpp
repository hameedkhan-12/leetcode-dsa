class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int countZeroes = 0;
        int productWithoutZeroes = 1;

        for(int num: nums){
            if(num == 0){
                countZeroes++;
            }else{
                productWithoutZeroes *= num;
            }
        }

        vector<int> result(n);
        for(int i = 0; i<n; i++){
            if(nums[i] != 0 && countZeroes > 0){
                result[i] = 0;
            }else if(nums[i] == 0 && countZeroes > 1){
                result[i] = 0;
            }else if(nums[i] == 0){
                result[i] = productWithoutZeroes;
            }else{
                result[i] = productWithoutZeroes / nums[i];
            }
        }
        return result;
    }
};