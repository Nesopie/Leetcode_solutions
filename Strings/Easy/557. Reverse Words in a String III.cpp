// Stack Solution
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string reverseWords(string s) {
        stack<char> reverse;
        string ans = "";

        for(char ch : s) {
            if(ch != ' ') {
                reverse.push(ch);
            }else {
                while(!reverse.empty()) {
                    ans += reverse.top();
                    reverse.pop();
                }ans += " ";
            }
        }

        while(!reverse.empty()) {
            ans += reverse.top();
            reverse.pop();
        }

        return ans;
    }
};

// Two Pointer Solution
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                int j = i;
                for(; j < s.length() && s[j] != ' '; j++) { };
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }

        return s;
    }
};
