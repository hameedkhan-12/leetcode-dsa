class Solution {
public:
    void solve(int ind, int target, vector<int>& nums, vector<int>& curr,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (ind == nums.size() || target < 0)
            return;

        curr.push_back(nums[ind]);
        solve(ind + 1, target - nums[ind], nums, curr, ans);
        curr.pop_back();

        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) {
            ind++;
        }
        solve(ind + 1, target, nums, curr, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, candidates, curr, ans);

        return ans;
    }
};