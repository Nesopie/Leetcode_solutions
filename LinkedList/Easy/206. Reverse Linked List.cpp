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

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* newHead = nullptr) {
        if(!head)
            return newHead;

        ListNode* next = head->next;
        head->next = newHead;

        return reverseList(next, head);
    }
};
