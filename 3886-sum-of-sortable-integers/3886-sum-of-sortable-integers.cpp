
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixMax(n + 1, 0);
        vector<int> suffixMin(n + 1, INT_MAX);
        vector<int> prefixDrop(n, 0);

        for (int i = 0; i < n; i++) {
            prefixMax[i + 1] = max(prefixMax[i], nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        for (int i = 1; i < n; i++) {
            prefixDrop[i] = prefixDrop[i - 1] + (nums[i - 1] > nums[i]);
        }

        auto check = [&](int k) {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                int drops = prefixDrop[end] - prefixDrop[start];

                if (nums[end] > nums[start]) {
                    drops++;
                }
                if (drops > 1) {
                    return false;
                }
                if (prefixMax[start] > suffixMin[start]) {
                    return false;
                }
            }
            return true;
        };

        int ans = 0;

        for (int k = 1; k <= n / k; k++) {
            if (n % k == 0) {
                if (check(k)) {
                    ans += k;
                }

                int other = n / k;
                if (other != k && check(other)) {
                    ans += other;
                }
            }
        }

        return ans;
    }
};
