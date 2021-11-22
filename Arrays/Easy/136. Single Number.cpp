// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;
        for(auto num : nums) {
            // a ^ a = 0
            // 0 ^ a = a
            singleNum ^= num;
        }

        return singleNum;
    }
};
