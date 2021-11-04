// Two pointer Solution
// Time Complexity: O(n)
// Space Complexity: O(1);

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddPointerWithEvenNumber = 0;
        int evenPointerWithOddNumber = 0;

        while(oddPointerWithEvenNumber < nums.size() && evenPointerWithOddNumber < nums.size()) {
            if((nums[oddPointerWithEvenNumber] & 1) == (oddPointerWithEvenNumber & 1)) {
                //if the index has the same parity as the value it holds then increment the pointer
                oddPointerWithEvenNumber++;
            }else if(!(oddPointerWithEvenNumber & 1) && (nums[oddPointerWithEvenNumber] & 1)) {
                //if the index is even and the value it holds is odd then move on as that's the job of even pointer
                oddPointerWithEvenNumber++;
            }else if(nums[evenPointerWithOddNumber] & 1) == (evenPointerWithOddNumber & 1) {
                //if the index has the same parity as the value it holds then increment the pointer
                evenPointerWithOddNumber++;
            }else if((evenPointerWithOddNumber & 1) && !(nums[evenPointerWithOddNumber] & 1)) {
                //if the index is odd and the value it holds is even then move on as that's the job of odd pointer
                evenPointerWithOddNumber++;
            }else {
                //if all conditions fail then oddPointerWithEvenNumber has odd index and the value it holds is even
                //and evenPointerWithOddNumber has even index and the value it holds is odd
                // on swapping the parity of the values change
                swap(nums[oddPointerWithEvenNumber], nums[evenPointerWithOddNumber]);
            }
        }

        return nums;
    }
};
