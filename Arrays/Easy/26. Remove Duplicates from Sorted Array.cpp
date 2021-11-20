// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicateCount = 0;
        for(int i = 1; i < (int)nums.size(); i++) {
            if(nums[i] == nums[i - 1]) duplicateCount++;
            else nums[i - duplicateCount] = nums[i];
            // If it's not duplicate then push the current number back by how many times duplicate numbers occured
        }

        return nums.size() - duplicateCount;
    }
};
