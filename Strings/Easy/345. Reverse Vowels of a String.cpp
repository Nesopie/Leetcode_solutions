// Two pointer solution
// Time Complexity: O(n)
// Space Complexity: o(1)

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            if(!isAVowel(s[left]))
                left++;
            else if(!isAVowel(s[right]))
                right--;
            else {
                swap(s[left++], s[right--]);
            }
        }

        return s;
    }

    bool isAVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
    }
};
