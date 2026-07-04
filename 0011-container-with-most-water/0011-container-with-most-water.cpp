class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        int minHeight = INT_MAX;
        while (left < right) {
            int width = right - left;
            minHeight = min(height[left], height[right]);
            maxWater = max(maxWater, width * minHeight);
            if (height[left] < height[right]) {
                left++;
            } else if (height[left] > height[right]) {
                right--;
            } else {
                left++;
                right--;
            }
        }
        return maxWater;
    }
};