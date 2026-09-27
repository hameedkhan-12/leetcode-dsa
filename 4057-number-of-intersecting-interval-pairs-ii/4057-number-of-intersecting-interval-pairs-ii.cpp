class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        long long result = 0;

        for (int i = 0; i < n; i++) {

            int end = intervals[i][1];
            int left = i + 1;
            int right = n;

            while (left < right) {
                int mid = left + (right - left) / 2;

                if (intervals[mid][0] <= end) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            result += left - (i + 1);
        }

        return result;
    }
};