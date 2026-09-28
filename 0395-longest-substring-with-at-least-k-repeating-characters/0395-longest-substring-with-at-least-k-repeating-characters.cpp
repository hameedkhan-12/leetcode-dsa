class Solution {
public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }
    int solve(string& s, int left, int right, int k) {
        if (right - left + 1 < k)
            return 0;

        int freq[26] = {};
        for (int i = left; i <= right; i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = left; i <= right; i++) {
            if (freq[s[i] - 'a'] < k) {
                int leftPart = solve(s, left, i - 1, k);
                int rightPart = solve(s, i + 1, right, k);
            return max(leftPart, rightPart);
            }
        }
        return (right - left + 1);
    }
};