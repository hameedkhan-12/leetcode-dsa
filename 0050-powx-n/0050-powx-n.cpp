class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        long long N = n;
        if(n<0){
            x = 1/x;
            N = -N;
        }
        return solve(x,N);
    }
    double solve(double x, long long n){
        if(n == 0) return 1;
        if(n == 1) return x;

        double half = solve(x, n/2);
        if(n%2==0) return half * half;
        return x * half * half;
    }
};