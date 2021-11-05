// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int currentNumber = 1;
        //current number in the list
        vector<string> result;

        for(int i = 0; i < target.size();) {
            if(currentNumber == target[i]) {
                result.push_back("Push");
                //if current number and target number are the same then push
                i++;
                currentNumber++;
            }else if(currentNumber < target[i]) {
                //if current number is less than target number then
                // it is not in the list, push and pop and iterate through the list
                result.push_back("Push");
                result.push_back("Pop");
                currentNumber++;
            }else {
                break;
            }
        }
        
        return result;
    }
};
