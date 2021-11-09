// Using Map to store indexes
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> mp;

        for(int i = 0; i < s.size(); i++) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;
            }else {
                mp[s[i]] = INT_MAX;
            }
        }

        int ans = INT_MAX;

        for(auto x : mp) {
            ans = min(ans, x.second);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// HashMap Solution
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26);

        for(char x : s) hash[x - 'a']++;

        for(int i = 0; i < s.size(); i++) {
            if(hash[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};
