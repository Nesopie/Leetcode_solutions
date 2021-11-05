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


// Two Pointer Solution
// Time Complexity: O(nlogn + mlogm)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        
        for(int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if(nums1[i] < nums2[j])
                i++;
            else if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i++]);
                j++;
            }else {
                j++;
            }
        }

        return result;
    }
};
