// HashMap Solution
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int result = -1;

        for(int num : arr) mp[num]++;

        for(auto x : mp) {
            if(x.first == x.second && x.first > result) {
                result = x.first;
            }
        }

        return result;
    }
};
