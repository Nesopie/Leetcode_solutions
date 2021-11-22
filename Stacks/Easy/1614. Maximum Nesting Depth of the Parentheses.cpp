// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxDepth(string s) {
        int maxNestingDepth = INT_MIN;
        int currentNestingDepth = 0;

        for(int i = 0; i < (int)s.length(); i++) {
            if(s[i] == '(') {
                currentNestingDepth++;
            }else if(s[i] == ')') {
                currentNestingDepth--;
            }
            maxNestingDepth = max(maxNestingDepth, currentNestingDepth);
        }

        return maxNestingDepth;
    }
};
