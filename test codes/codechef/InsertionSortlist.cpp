class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v;
        int i=0;
        ListNode* t1=new ListNode();
        ListNode* t2=t1;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        while(i<v.size()){
            ListNode* temp=new ListNode(v[i]);
            t1->next=temp;
            t1=t1->next;
            i++;
        }
        return t2->next;
    }
};
