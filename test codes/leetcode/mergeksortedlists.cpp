#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        } else if (n == 1) {
            return lists[0];
        }
        int mid = n / 2;
        vector<ListNode*> left(lists.begin(), lists.begin() + mid);
        vector<ListNode*> right(lists.begin() + mid, lists.end());
        ListNode* leftMerged = mergeKLists(left);
        ListNode* rightMerged = mergeKLists(right);
        return mergeTwoLists(leftMerged, rightMerged);
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        return dummy.next;
    }
};
