class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);

        addPerm(ans, curr, nums, visited);
        return ans;
    }
    void addPerm(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums,
                 vector<bool> visited) {
        if (nums.size() == curr.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            visited[i] = true;

            curr.push_back(nums[i]);
            addPerm(ans, curr, nums, visited);
            curr.pop_back();
            visited[i] = false;
        }
    }
};