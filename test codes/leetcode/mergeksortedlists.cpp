#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto& head : lists) {
            if (head) pq.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = curr;
            if (curr->next) pq.push(curr->next);
        }

        return dummy.next;
    }
};
int main() {
    vector<ListNode*> lists = {
        createLinkedList({1, 4, 5}),
        createLinkedList({1, 3, 4}),
        createLinkedList({2, 6})
    };

    Solution sol;
    ListNode* mergedList = sol.mergeKLists(lists);

    printLinkedList(mergedList);

    return 0;
}
