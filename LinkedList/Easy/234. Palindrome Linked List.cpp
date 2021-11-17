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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = head;
        slow = reverseList(slow);

        while(fast && slow) {
            if(fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next;

        while(current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};
