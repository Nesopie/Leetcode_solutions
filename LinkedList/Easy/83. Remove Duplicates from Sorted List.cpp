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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        while(temp) {
            if(temp->next && (temp->val == temp->next->val)) {
                ListNode* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }else {
                temp = temp->next;
            }
        }

        return head;
    }
};
