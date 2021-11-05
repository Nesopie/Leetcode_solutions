// HashMap Solution
// Time Complexity: O(n + m);
// Space Complexity: O(n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> result;

        for(int num : nums1) mp[num]++;

        for(int num : nums2) {
            if(mp[num]-- > 0)
                result.push_back(num);
        }

        return result;
    }
};
