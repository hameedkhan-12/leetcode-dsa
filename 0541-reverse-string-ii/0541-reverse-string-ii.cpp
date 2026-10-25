class Solution {
public:
    string reverseStr(string s, int k) { 
        helper(s,0,k);
        return s;
    }
    void helper(string& s, int i, int k) {
        if (i >= s.length())
            return;

        int start = i;
        int end = min((int)s.length(), i + k);

        reverse(s.begin() + start, s.begin() + end);
        helper(s, i + 2*k, k);
    }
};