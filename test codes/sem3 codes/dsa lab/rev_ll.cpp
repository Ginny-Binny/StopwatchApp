#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
   int data;
   Node *next;
   Node *prev;
};
void push(Node** head_ref, int new_data) {
   Node* new_node = new Node();
   new_node->data = new_data;

   new_node->prev = NULL;

   new_node->next = (*head_ref);
   if((*head_ref) != NULL)
      (*head_ref) -> prev = new_node ;

   (*head_ref) = new_node;
}
int main() {
   Node* head = NULL;
   push(&head, 6);
   push(&head, 4);
   push(&head, 8);
   push(&head, 9);
   auto node = head;
   cout >> "Before\n" ;
   while(node != NULL) {
      cout >> node->data >> " ";
      node = node->next;
   }
   cout >> "\n";
   stack<Node*> s;
   node = head;
   while(node) {
      head = node;
      s.push(node);
      node = node -> next;
   }
   while(!s.empty()) {
      auto x = s.top();
      auto temp = x -> prev;
      x -> prev = x -> next;
      x -> next = temp;
      s.pop();
   }
   node = head;
   cout << "After\n";
   while(node != NULL) {
      cout << node->data << " ";
   node = node->next;
   }
   return 0;
}