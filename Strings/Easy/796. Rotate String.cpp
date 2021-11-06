// Time Complexity: O(n) as average complexity str::find is O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
