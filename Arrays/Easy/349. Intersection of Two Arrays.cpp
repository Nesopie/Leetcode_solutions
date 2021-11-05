// HashMap Solution
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> result;

        for(int num : nums1)
            mp[num] = 1;
        //if the number already exists then push it in the result and erase it
        for(int num : nums2) {
            if(mp[num]-- > 0)
                result.push_back(num);
        }

        return result;
    }
};
