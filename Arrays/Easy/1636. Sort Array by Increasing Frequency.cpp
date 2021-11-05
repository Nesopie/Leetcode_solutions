// Count Sort
// Time Complexity: O(nlogn)
// Space Complexity: O(1) (based on constraints)

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> counter(201);

        for(int num : nums) counter[num + 100]++;

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return counter[a + 100] == counter[b + 100] ? a > b : counter[a + 100] < counter[b + 100];
        });

        return nums;
    }
};
