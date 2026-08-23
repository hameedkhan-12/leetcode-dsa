class Solution {
public:
    void solve(int num, int n, int k, vector<int>& curr,
               vector<vector<int>>& ans) {

        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        if (num > n)
            return;

        curr.push_back(num);
        solve(num + 1, n, k, curr, ans);
        curr.pop_back();
        solve(num + 1, n, k, curr, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, n, k, curr, ans);
        return ans;
    }
};