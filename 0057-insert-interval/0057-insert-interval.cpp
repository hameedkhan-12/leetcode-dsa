class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }else{
                merged.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        merged.push_back({start,end});
        return merged;
    }
};