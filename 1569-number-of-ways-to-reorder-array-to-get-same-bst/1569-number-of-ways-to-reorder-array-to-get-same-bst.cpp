
class Solution {
public:
    const long long MOD = 1e9 + 7;

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> C(
            n, vector<long long>(n, 0)
        );

        for (int i = 0; i < n; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] =
                    (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        function<long long(vector<int>&)> solve =
            [&](vector<int>& arr) -> long long {

            int n = arr.size();

            if (n <= 2) {
                return 1;
            }

            int root = arr[0];

            vector<int> left, right;
            for (int i = 1; i < n; i++) {
                if (arr[i] < root) {
                    left.push_back(arr[i]);
                } else {
                    right.push_back(arr[i]);
                }
            }

            long long waysLeft = solve(left);
            long long waysRight = solve(right);

            // Interleave left and right subtree elements
            long long ways = C[n - 1][left.size()];
            ways = ways * waysLeft % MOD;
            ways = ways * waysRight % MOD;

            return ways;
        };
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
