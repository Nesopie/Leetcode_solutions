//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOperations = 0;
        int previousNumber = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(previousNumber >= nums[i]) {
                // perform the minimum number of operations, that is, increase the current number by 1;
                minOperations += previousNumber - nums[i] + 1;
                //previous number is now the current number + 1
                previousNumber++;
            }else {
                // 1 5 2 4 1
                //if previous number is smaller, make the current number as the previous number
                previousNumber = nums[i];
            }
        }

        return minOperations;
    }
};
