// Using constraints and counting sort
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> counter(1001);

        for(int n : arr1) counter[n]++;

        int i = 0;

        for(int num : arr2) {
            while(counter[num]-- > 0) {
                arr1[i++] = num;
            }
        }

        for(int j = 0; j < counter.size(); j++) {
            while(counter[j]-- > 0) {
                arr1[i++] = j;
            }
        }

        return arr1;
    }
};

// Using HashMap
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;

        for(int num : arr1) mp[num]++;

        int i = 0;

        for(int num : arr2) {
            while(mp[num]-- > 0) {
                arr1[i++] = num;
            }
            mp.erase(num);
        }

        for(auto x : mp) {
            while(x.second-- > 0) {
                arr1[i++] = x.first;
            }
        }

        return arr1;
    }
};
