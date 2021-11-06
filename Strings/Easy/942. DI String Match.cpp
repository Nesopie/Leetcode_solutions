// Two pointer ? solution
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result;
        int small = 0;
        int large = s.size();
        for(int i = 0; i < s.size(); i++) {
            result.push_back(s[i] == 'I' ? small++ : large--);
        }

        result.push_back(small);
        //push small or large, doesn't matter since both will be the same

        return result;
    }
};
