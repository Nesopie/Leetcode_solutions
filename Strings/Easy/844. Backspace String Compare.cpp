// Two Pointer Solution
// Time Complexity: O(n)
// Space Complxity: O(1)

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        while(1) {
            int goBackForS = 0;
            int goBackForT = 0;
            while(i >= 0 && (goBackForS || s[i] == '#')) {
                if(s[i] == '#') {
                    goBackForS++;
                }
                else {
                    goBackForS--;
                }
                i--;
            }

            while(j >= 0 && (goBackForT || t[j] == '#')) {
                if(t[j] == '#') {
                    goBackForT++;
                }else {
                    goBackForT--;
                }
                j--;
            }

            if(i >= 0 && j >= 0 && s[i] == t[j]) {
                i--;
                j--;
            }
            else
                break;
        }
        // if one of the strings has reached the end then the result is false
        // the result is also false because of the break condition since both the
        // iterators are inside the string
        // For example s = "c" and t = "d"
        // the while loop breaks at this condition
        return i == -1 && j == -1;
    }
};
