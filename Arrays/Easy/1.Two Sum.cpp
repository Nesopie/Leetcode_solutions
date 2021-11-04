// Two pointer algorithm using sorted array
// Time Complexity: O(nlogn);
// Space Complexity: O(1);

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vec;
        for(int i = 0; i < nums.size(); i++) {
            vec.push_back(pair(nums[i],i));
        }
        sort(vec.begin(), vec.end());

        int i = 0;
        int j = vec.size() - 1;

        vector<int> result;

        while(i < j) {
            int sum = vec[i].first + vec[j].first;
            if(sum < target) {
                i++;
            }else if(sum > target) {
                j--;
            }else {
                result.push_back(vec[i].second);
                result.push_back(vec[j].second);
                break;
            }
        }

        return result;
    }
};

//Using HashMap Solution
//Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            if(hash.find(target - nums[i]) != hash.end()) {
                result.push_back(hash[target - nums[i]]);
                result.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }

        return result;
    }
};
