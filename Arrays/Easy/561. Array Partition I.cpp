//Time Complexity: O(nlogn)
//Space Complexity: O(1)

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //since min number is chosen at the sacrifice of the bigger number,
        //the difference between them should be minimum
        sort(nums.begin(), nums.end());
        int sum = 0;

        for(int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};
