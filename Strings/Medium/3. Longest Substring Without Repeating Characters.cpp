// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int left = 0;
        int right = 0;

        int maxLength = 0;

        while(right < s.length()) {
            // If the character is already encountered then,
            // left = left if the character is encountered but not in the string
            // hash[s[right]] + 1 if the character is encountered and is in the string
            if(hash[s[right]] != -1) {
                left = max(left,hash[s[right]] + 1);
            }

            hash[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};
