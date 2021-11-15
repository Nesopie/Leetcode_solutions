// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minimumMoves(string s) {
        int minMoves = 0;
        for(int i = 0; i < s.length(); i+=3) {
            while(s[i] != 'X' && i < s.length()) i++; // skip if all zeroes
            if((i < s.length() && s[i] == 'X')) // found an X increment by 3
                minMoves++;
        }

        return minMoves;
    }
};
