#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
int main() {
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    
    Solution sol;
    TreeNode* root = sol.sortedListToBST(head);
    
    // Test if the constructed tree is a binary search tree
    // Inorder traversal should return sorted values
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node) {
            return;
        }
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    };
    inorder(root); // expected output: -10 -3 0 5 9 
    
    return 0;
}
