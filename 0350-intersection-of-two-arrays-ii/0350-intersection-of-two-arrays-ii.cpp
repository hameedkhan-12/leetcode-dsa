class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> seen;
        vector<int> result;

        for (int num : nums1) {
            seen[num]++;
        }

        for (int num : nums2) {
            if (seen.count(num) && seen[num] > 0) {
                result.push_back(num);
                seen[num]--;

                if (seen[num] == 0) {
                    seen.erase(num);
                }
            }
        }
        return result;
    }
};