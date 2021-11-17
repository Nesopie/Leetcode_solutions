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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;

        while(temp) {
            if(temp->val == val) {
                head = temp->next;
                delete temp;
                temp = head;
            }else {
                if(temp->next && temp->next->val == val) {
                    ListNode* remove = temp->next;
                    temp->next = temp->next->next;
                    delete remove;
                }else {
                    temp = temp->next;
                }
            }
        }
        
        return head;
    }
};
