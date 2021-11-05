// Counting sort and using constraints
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> bucket(1001);

        for(int num : nums)
            bucket[num]++;

        int currentTotal = nums.size();

        for(int i = 0; i < bucket.size(); i++) {
            if(i == currentTotal)
                return i;
            currentTotal -= bucket[i];
        }

        return -1;
    }
};

// Sorting and binary search
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums[0] >= nums.size()) return nums.size();

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int middle = low + (high - low)/2;
            if(nums[middle] >= (nums.size() - middle) && nums[middle - 1] < nums.size() - middle)
                return nums.size() - middle;
            else if(nums[middle] >= (nums.size() - middle))
                high = middle - 1;
            else
                low = middle + 1;
        }

        return -1;
    }
};
