//Time Complexity: O(nlogn)
//Space Complexity: O(1)

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //since min number is chosen at the sacrifice of the bigger number,
        //the difference between them should be minimum
        sort(nums.begin(), nums.end());
        int sum = 0;

        for(int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};

//Using simple HashMap and counting sort idea
//Time Complexity: O(n)
//Space Complexity: O(2 * 10^4 + 1)

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> hash(2 * 10e4 + 1);
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i] + 10e4]++;
        }

        bool shouldPick = true;
        int sum = 0;

        for(int i = 0; i < hash.size(); i++) {
            while(hash[i] > 0) {
                if(shouldPick) {
                    sum += (i - 10e4);
                }
                hash[i]--;
                shouldPick = !shouldPick;
            }
        }

        return sum;
    }
};
