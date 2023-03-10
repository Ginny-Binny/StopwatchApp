#include <cstdlib>
#include <ctime>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL));
    }
    
    int getRandom() {
        ListNode* node = head;
        int count = 1;
        int result = 0;
        while (node) {
            if (rand() % count == 0) {
                result = node->val;
            }
            count++;
            node = node->next;
        }
        return result;
    }
};
