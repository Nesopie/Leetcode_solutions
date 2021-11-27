// HashMap solution
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> isJewel;
        for(auto x : jewels) {
            isJewel[x] = 1;
        }

        int numberOfJewels = 0;

        for(auto x : stones) {
            if(isJewel.find(x) != isJewel.end()) {
                numberOfJewels++;
            }
        }

        return numberOfJewels;
    }
};
