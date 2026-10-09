class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i + 1 == s.size() || s[i + 1] != ')') {
                    insertions++;
                } else {
                    i++;
                }
                if (open > 0) {
                    open--;
                } else {
                    insertions++;
                }
            }
        }
        return insertions + open * 2;
    }
};