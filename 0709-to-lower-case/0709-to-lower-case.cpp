class Solution {
public:
    string toLowerCase(string s) {
        toLower(s, 0);
        return s;
    }
    void toLower(string& s, int next) {
        if (next >= s.size())
            return;

        if (s[next] >= 'A' && s[next] <= 'Z') {
            s[next] += 32;
        }
        toLower(s, next + 1);
    }
};