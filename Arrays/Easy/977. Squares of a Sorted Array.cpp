// Two Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // take the last negative integer index and using two pointers from there
        int lastNegativeIntegerIndex = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                lastNegativeIntegerIndex = i;
            }else {
                break;
            }
        }
        //even if there's no negative integer, first positive integer will be -1 + 1 = 0
        int i = lastNegativeIntegerIndex;
        int j = i + 1;
        vector<int> result;

        while((i >= 0) && (j < nums.size())) {
            //two pointers i and j
            if(abs(nums[i]) < abs(nums[j])) {
                result.push_back(nums[i] * nums[i--]);
            }else {
                result.push_back(nums[j] * nums[j++]);
            }
        }
        //j might have reached the end but not i
        while(i >= 0) {
            result.push_back(nums[i] * nums[i--]);
        }
        //i might have reached the end but not j
        while(j < nums.size()) {
            result.push_back(nums[j] * nums[j++]);
        }

        return result;
    }
};
