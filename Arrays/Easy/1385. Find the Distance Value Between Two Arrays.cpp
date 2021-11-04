// Binary Search solution 
// Time Complexity: O(m * log(n))
// Space Complexity: O(1)

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;
        // find the range which satisfies the equation
        // x - element in arr2 = ±d
        // if the length of this range is 0 then increment the answer
        for(auto x : arr1) {
            if((lower_bound(arr2.begin(), arr2.end(), x - d) - upper_bound(arr2.begin(), arr2.end(), x + d)) == 0) ans++;
        }

        return ans;
    }
};
