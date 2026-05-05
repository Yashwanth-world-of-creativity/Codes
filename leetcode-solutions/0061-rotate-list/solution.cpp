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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;

        // Step 1: find length and last node
        int n = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            n++;
        }

        // Step 2: make it circular
        tail->next = head;

        // Step 3: reduce k
        k = k % n;

        // Step 4: find new tail (n-k-1 steps)
        int steps = n - k;
        ListNode* newTail = head;
        while(--steps){
            newTail = newTail->next;
        }

        // Step 5: break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
