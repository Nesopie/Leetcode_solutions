// Time Complexity: O(n);
// Space Complexity: O(1);

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for(int i = 0; i < indices.size(); i++) {
            while(indices[i] != i) {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }
        return s;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result = s;
        for(int i = 0; i < s.size(); i++) {
            result[indices[i]] = s[i];
        }

        return result;
    }
};
