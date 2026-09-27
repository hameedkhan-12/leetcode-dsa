class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int result =0;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int start1 = intervals[i][0];
                int end1 = intervals[i][1];
                int start2 = intervals[j][0];
                int end2 = intervals[j][1];
                if(max(start1,start2) <= min(end1,end2)){
                    result++;
                }
            }
        }
        return result;
    }
};