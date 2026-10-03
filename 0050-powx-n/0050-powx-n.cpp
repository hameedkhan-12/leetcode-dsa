class Solution {
public:
    double myPow(double x, int n) {
        unsigned long long N = abs((long long)n);

        if (x == 0)
            return 0;

        double res = 1.0;

        while (N > 0) {
            if (N % 2 == 1) {
                res *= x;
            }
            x *= x;
            N /= 2;
        }
        return n < 0 ? 1.0 / res : res;
    }
};