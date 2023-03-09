ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // cycle detected
            ListNode *ptr1 = head;
            ListNode *ptr2 = slow;
            while (ptr1 != ptr2) { // find the cycle start node
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }
    }
    return NULL; // no cycle detected
}