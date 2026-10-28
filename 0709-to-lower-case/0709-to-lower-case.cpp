class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
            ans += c;
        }
        return ans;
    }
};