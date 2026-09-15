class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftProd(n);
        vector<int>rightProd(n);

        leftProd[0] = 1;
        rightProd[n-1] = 1;
        for(int i = 1; i<n; i++){
            leftProd[i] = leftProd[i-1] * nums[i-1]; 
        }
        for(int i = n-2; i>=0; i--){
            rightProd[i] = rightProd[i+1] * nums[i+1];
        }

        vector<int> result(n);
        for(int i = 0; i<n; i++){
            result[i] = leftProd[i] * rightProd[i];
        }
        return result;
    }
};