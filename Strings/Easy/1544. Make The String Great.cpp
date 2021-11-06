// Stack Solution
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(!st.empty() && (abs(s[i] - st.top()) == abs('a' - 'A'))) {
                st.pop();
            }else {
                st.push(s[i]);
            }
        }

        string ans = "";

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Array stack simulation Solution using pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string makeGood(string s) {
        int p = 0;
        for(int i = 0; i < s.size(); i++) {
            // p > 0 is the same as !st.empty() and p - 1 is the top
            if(p > 0 && (abs(s[i] - s[p - 1]) == abs('a' - 'A')))
                p--; //p-- is the same as popping
            else
                s[p++] = s[i]; //pushing the element, in this case we are just replacing top
                // with current element and incrementing p
        }

        return s.substr(0,p);
    }
};
