// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }

    bool halvesAreAlike(string s) {
        if(s.length() & 1) return false;
        int rightHalfPointer = s.length() / 2;
        int leftHalfPointer = 0;

        int leftHalfCounter = 0;
        int rightHalfCounter = 0;

        while(leftHalfPointer < s.length() / 2 && rightHalfPointer < s.length()) {
            if(isVowel(s[leftHalfPointer++]))
                leftHalfCounter++;
            if(isVowel(s[rightHalfPointer]))
                rightHalfCounter++;
        }

        return leftHalfCounter == rightHalfCounter;
    }
};
