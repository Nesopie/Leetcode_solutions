/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimalValue = 0;

        ListNode* temp = head;
        while(temp) {
            decimalValue *= 2;
            decimalValue += temp->val;
            temp = temp->next;
        }

        return decimalValue;
    }
};
