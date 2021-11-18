/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int topLength = headA ? 1 : 0;
        int bottomLength = headB ? 1 : 0;

        ListNode* temp = headA;
        while(temp) {
            temp = temp->next;
            topLength++;
        }

        temp = headB;
        while(temp) {
            temp = temp->next;
            bottomLength++;
        }

        ListNode* topStart = headA;
        ListNode* bottomStart = headB;

        if(topLength > bottomLength) {
            int difference = topLength - bottomLength;
            while(difference--) {
                topStart = topStart->next;
            }
        }else {
            int difference = bottomLength - topLength;
            while(difference--) {
                bottomStart = bottomStart->next;
            }
        }

        while(topStart && bottomStart) {
            if(topStart == bottomStart) {
                return topStart;
            }
            topStart = topStart->next;
            bottomStart = bottomStart->next;
        }

        return nullptr;
    }
};
