// Time Complexity: O(n + m)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;

        for(int i = nums2.size() - 1; i >= 0; i--) {
            // find next greater elements using stack and store them in hashmap
            while(!st.empty() && nums2[i] > st.top())
                st.pop();
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        vector<int> nextGreaterElements(num1.size());

        for(int i = 0; i < nums1.size(); i++) {
            nextGreaterElements[i] = mp[nums1[i]];
        }

        return nextGreaterElements;
    }
};
