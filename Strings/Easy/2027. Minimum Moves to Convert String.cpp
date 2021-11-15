// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minimumMoves(string s) {
        int minMoves = 0;
        for(int i = 0; i < s.length(); i+=3) {
            while(s[i] != 'X' && i < s.length()) i++; // skip if all zeroes
            if((i < s.length() && s[i] == 'X') ||  //if even one is X include it and jump 3 steps
               (i + 1 < s.length() && s[i + 1] == 'X')||
               (i + 2 < s.length() && s[i + 2] == 'X'))
                minMoves++;
        }

        return minMoves;
    }
};
