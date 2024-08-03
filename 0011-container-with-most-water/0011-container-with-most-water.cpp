class Solution {
public:
    int maxArea(vector<int>& height) {
        int pt1 = 0;
        int pt2 = height.size() - 1;
        int maxArea = 0;

        while (pt1 < pt2) {
            int area = min(height[pt1], height[pt2]) * (pt2 - pt1);
            maxArea = max(maxArea, area);

            if (height[pt1] < height[pt2]) {
                pt1++;
            } else {
                pt2--;
            }
        }

        return maxArea;
    }
};