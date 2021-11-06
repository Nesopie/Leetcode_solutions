// Greedy Solution
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int balancedStringSplit(string s) {
        int numberOfLefts = 0;
        int numberOfRights = 0;
        int balanceCounter = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'L')
                numberOfLefts++;
            else
                numberOfRights++;
            if(numberOfLefts == numberOfRights) {
                numberOfLefts = numberOfRights = 0;
                balanceCounter++;
            }
        }

        return balanceCounter;
    }
};
