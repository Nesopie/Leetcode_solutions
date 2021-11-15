// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string reformat(string s) {
        string alphabetString = "";
        string digitString = "";

        for(char ch : s)
            isalpha(ch) ? alphabetString.push_back(ch) : digitString.push_back(ch);

        if(abs((int)alphabetString.length() - (int)digitString.length()) > 1)
            return "";

        bool isAlpha = alphabetString.length() > digitString.length();
        int i = 0;
        int alphabetPointer = 0;
        int digitPointer = 0;

        while(i < s.length()) {
            if(isAlpha)
                s[i++] = alphabetString[alphabetPointer++];
            else
                s[i++] = digitString[digitPointer++];
            isAlpha = !isAlpha;
        }

        return s;
    }
};
