class Solution {
public:
    int integerReplacement(int n) {

        long long x = n;
        int result = 0;

        while (x != 1) {

            if (x % 2 == 0) {
                x /= 2;
            }
            else if (x == 3) {
                x--;
            }
            else if (x & 2) {
                x++;
            }
            else {
                x--;
            }
            result++;
        }
        return result;
    }
};