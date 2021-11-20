// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = INT_MIN;
        int leftLine = 0;
        int rightLine = height.size() - 1;

        while(leftLine < rightLine) {
            int current_area = (rightLine - leftLine) * min(height[rightLine] ,height[leftLine]);
            max_area = max(max_area,current_area);
            //    Don't move the bigger line since 
            // a) if it's bigger than the current line then the area will be the same as water is limited by
            // the smaller line
            // b) if it's smaller than the current line then the area will decrease / stay the same
            height[leftLine] < height[rightLine] ? leftLine++ : rightLine--;
        }

        return max_area;
    }
};
