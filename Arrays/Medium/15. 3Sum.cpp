// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(),nums.end());

        for(int constant = 0; constant < nums.size(); constant++) {
            // Have a constant value and do 2sum for the other two
            int left = constant + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[constant] + nums[left] + nums[right];
                if(sum < 0)
                    left++;
                else if(sum > 0)
                    right--;
                else {
                    result.push_back({nums[constant], nums[left], nums[right]});
                    // Skip duplicates
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
            while(constant + 1 < nums.size() && nums[constant] == nums[constant + 1])
                constant++;
        }

        return result;
    }
};
