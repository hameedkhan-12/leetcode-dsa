
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        string ans = "";

        int totalNines = sum / 9;
        int remainder = sum % 9;

        ans += string(totalNines, '9');

        if (remainder > 0) {
            ans += char('0' + remainder);
        }

        ans += string(num - ans.size(), '0');
        return ans;
    }
};
