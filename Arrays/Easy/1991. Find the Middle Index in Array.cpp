// Postfix Solution
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        int middleIndex = -1;

        for(int i = 0; i < nums.size() - 1; i++) {
            rightSum += nums[i + 1];
        }

        if(leftSum == rightSum) return 0;

        for(int i = 1; i < nums.size(); i++) {
            leftSum += nums[i - 1];
            rightSum -= nums[i];

            if(leftSum == rightSum) {
                middleIndex = i;
                break;
            }
        }

        return middleIndex;
    }
};
