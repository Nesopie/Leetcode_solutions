// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int currentLine = 1;
        int currentWidth = 0;

        for(int i = 0; i < s.size(); i++) {
            if(currentWidth + widths[s[i] - 'a'] > 100) {
                currentLine++;
                currentWidth = 0;
                i--;
            }else {
                currentWidth += widths[s[i] - 'a'];
            }
        }

        return vector<int> ({currentLine, currentWidth});
    }
};
