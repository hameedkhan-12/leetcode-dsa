class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
                result.back()[1] = end;
            }else{
                result.push_back(intervals[i]);
                end = intervals[i][1];
            }
        }
        return result;
    }
};