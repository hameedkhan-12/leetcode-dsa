class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (1LL * m * k > n) return -1;

        long long left = *min_element(bloomDay.begin(), bloomDay.end());
        long long right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            long long mid = left + (right - left) / 2;

            int bouqets = calcBouqet(bloomDay, mid, k);
            if(bouqets < m){
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        return left;
    }
    int calcBouqet(vector<int>& bloomDay, int days, int k){
        int flowers = 0;
        int bouqets = 0;
        for(double day: bloomDay){
            if(day<=days){
                flowers++;
            }else{
                bouqets += flowers/k;
                flowers = 0;
            }
        }
        bouqets += flowers/k;

        return bouqets;
    }
};