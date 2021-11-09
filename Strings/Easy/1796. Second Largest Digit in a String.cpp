// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int secondHighest(string s) {
        int biggest = INT_MIN;
        int secondBiggest = INT_MIN;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int number = s[i] - '0';
                if(number > biggest) {
                    secondBiggest = biggest;
                    biggest = number;
                }else if(number > secondBiggest && number < biggest) { // second proposition is used to prevent when digits are repeated
                    secondBiggest = number;
                }
            }
        }

        return secondBiggest == INT_MIN ? -1 : secondBiggest;
    }
};
