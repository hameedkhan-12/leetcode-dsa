class Solution {
public:
    bool isPalindrome(string s) { return checkPal(s, 0, (int)s.size() - 1); }

    bool checkPal(string& s, int left, int right) {
        if (left >= right)
            return true;

        if (!isalnum(s[left]))
            return checkPal(s, left + 1, right);
        if (!isalnum(s[right]))
            return checkPal(s, left, right-1);

        if (tolower(s[left]) != tolower(s[right]))
            return false;

        return checkPal(s, left + 1, right - 1);
    }
};