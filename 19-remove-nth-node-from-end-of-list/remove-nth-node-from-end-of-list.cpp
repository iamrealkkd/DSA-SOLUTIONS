class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Create a dummy node before the head.
        // This eliminates the special case of deleting the first node,
        // because every node (including the original head) now has a previous node.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Initialize both pointers at the dummy node.
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Step 3: Move 'fast' exactly (n + 1) steps ahead.
        // Why n + 1?
        // We want 'slow' to stop at the PREVIOUS node of the node to be deleted.
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Step 4: Move both pointers together.
        // Maintain the fixed gap of (n + 1) nodes.
        // When 'fast' reaches NULL, 'slow' will be just before
        // the node that needs to be removed.
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 5: Remove the target node.
        // Skip the nth node from the end by changing the next pointer.
        slow->next = slow->next->next;

        // Step 6: Return the updated head.
        // It may change if the original head was deleted.
        return dummy->next;
    }
};