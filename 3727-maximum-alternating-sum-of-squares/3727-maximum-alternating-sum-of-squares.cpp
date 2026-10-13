
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;

        for (int num : nums) {
            squares.push_back(1LL * num * num);
        }

        sort(squares.begin(), squares.end());
        int n = squares.size();
        int half = n / 2;
        long long ans = 0;

        for (int i = 0; i < half; i++) {
            ans -= squares[i];
        }
        for (int i = half; i < n; i++) {
            ans += squares[i];
        }
        return ans;
    }
};
