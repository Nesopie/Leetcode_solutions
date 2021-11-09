// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mymap;
        for(string str : arr) mymap[str]++;

        int counter = 0;

        for(string str : arr) {
            if(mymap[str] == 1) {
                counter++;
                if(counter == k) return str;
            }
        }

        return "";
    }
};
