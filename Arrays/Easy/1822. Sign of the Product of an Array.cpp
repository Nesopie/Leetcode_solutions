// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int numberOfNegatives = 0;
        for(int num : nums) {
            if(num == 0)
                return 0;
            if(num < 0)
                numberOfNegatives++;
        }

        if(numberOfNegatives & 1)
            return -1;
        return 1;
    }
};
