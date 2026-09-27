class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; i++) {
            solve(i, n, result);
        }

        return result;
    }
    void solve(int currentNum, int n, vector<int>& result) {
        if (currentNum > n)
            return;
        result.push_back(currentNum);

        for (int append = 0; append <= 9; append++) {
            int newNum = (currentNum * 10) + append;
            if (newNum > n)
                return;

            solve(newNum, n, result);
        }
    }
};