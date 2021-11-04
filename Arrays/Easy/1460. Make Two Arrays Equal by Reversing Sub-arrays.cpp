// HashMap solution
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // the given array can always be converted to the target array(by swapping two elements at a time)
        // if and only if the two arrays contain the same elements in the same amount
        unordered_map<int,int> hash;
        for(int num : target) hash[num]++;

        for(int num : arr) {
            // first check if there's the different number and second, if they exist in the same amount
            if(!hash[num] || --hash[num] == -1) return false;
        }

        return true;
    }
};
