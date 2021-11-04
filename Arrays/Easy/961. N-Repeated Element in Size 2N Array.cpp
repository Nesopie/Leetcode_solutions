// Using Hashmap
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;

        int ans;
        for(int num : nums) {
            if(mp[num]) {
                // since there are atleast n + 1 distinct numbers, if a number is repeated at least one return it
                ans = num;
                break;
            }else {
                mp[num]++;
            }
        }

        return ans;
    }
};

// Using given question logic
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i = 2; i < nums.size(); i++) {
            // If no two consecutive integers are the same then n repeated integers are alternating, nums[i] == nums[i - 2]
            // If they are not alternating, then to compensate the alternating pattern, two of them should be together, nums[i] == nums[i - 1]
            // If not then the answer is nums[0] since we aren't checking that as the loop starts at 2, or the numbers are at the end of the array, nums[3,1,2,3]
            if(nums[i] == nums[i - 1] || nums[i] == nums[i - 2]) {
                return nums[i];
            }
        }
        return nums[0];
    }
};
