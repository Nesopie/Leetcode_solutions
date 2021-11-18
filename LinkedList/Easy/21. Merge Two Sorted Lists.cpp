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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyHead = ListNode();

        if(!l1) return l2;
        else if(!l2) return l1;

        if(l1->val < l2->val) {
            dummyHead.next = l1;
            l1 = l1->next;
        }else {
            dummyHead.next = l2;
            l2 = l2->next;
        }

        ListNode *curr = dummyHead.next;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        if(!l1) {
            curr->next = l2;
        }else {
            curr->next = l1;
        }

        return dummyHead.next;
    }
};
