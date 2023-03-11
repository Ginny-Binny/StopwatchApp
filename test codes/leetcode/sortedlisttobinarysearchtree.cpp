class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }
        return sortedListToBST(head, NULL);
    }
    
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return NULL;
        }
        ListNode* mid = findMid(head, tail);
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(mid->next, tail);
        return root;
    }
    
    ListNode* findMid(ListNode* head, ListNode* tail) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Test the solution
