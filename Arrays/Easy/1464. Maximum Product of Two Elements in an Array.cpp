// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest = 0;
        int secondBiggest = 0;

        for(int num : nums) {
            if(num > biggest) {
                //if current number greater than the biggest number then
                // secondBiggest = biggest and biggest = currentNumber
                secondBiggest = exchange(biggest, num);
            }else {
                //don't worry about biggest now, secondeBiggest is the
                //largest of current secondBiggest number and current number
                secondBiggest = max(secondBiggest, num);
            }
        }

        return (biggest - 1) * (secondBiggest - 1);
    }
};
