// Time Complexity: O(n)
// Space Complexity: o(1)

class Solution {
public:
    string sortString(string s) {
        vector<int> hash(26);

        for(int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }

        string result = "";
        int currentSize = 0;

        int i = 0;
        int direction = 1;
        //just take all the letters in alphabetical order and then reverse alphabetical order one at a time
        while(i < 26 && i >= 0) {
            if(hash[i] > 0) {
                result.push_back('a' + i);
                hash[i]--;
                currentSize++;
            }
            // 0 to 25 and then 25 to 0
            if((i == 25 && direction == 1) || (i == 0 && direction == -1))
                direction *= -1;
            else
                i += direction;
            if(currentSize == s.size()) break;

        }

        return result;
    }
};
