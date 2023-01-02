#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// implimentation of a node o fhte linked list
class Node{
    public:
    int data;
    Node* next; 
    Node(){
        data = 0;
        next = NULL;
    }
};
// for traversal of the nodes
void linkedListTraversal(Node* head){
    while(head != NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int isEmpty(Node* head){
    if(head == NULL){
        cout<<"Underflow condition"<<endl;
        return 1;
    }
    else{return 0;}
}

int isFull(Node* head){
    Node* n = new Node;
    if(n == NULL){
        cout<<"Overflow condition"<<endl;
        return 1;
    }
    else{return 0;}
}

// insertion in the list at the end 
Node* insertAtEnd(Node* head, int val){
    if(isFull(head)){
        return 0;
    }

    Node* new_node = new Node;
    new_node-> data = val;
    
    Node* p = head;
    while(p->next != NULL){ // traversing to the end of the list
        p = p->next;
    }
    p->next = new_node; // adding the created node
    new_node->next = NULL; 
    return head;
}

void deleteAtEnd(Node* head){
    Node* ptr = head;
    Node* p = head->next;
    while(p->next != NULL){
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    delete p;
    // return head;
}

void positionOfNode(Node* head, int val){
    Node* ptr = head;
    int index = 0;
    int i = 0;
    while(ptr != NULL){
        if(ptr->data == val){
            index = i;
            break;
        }
        i++;
        ptr = ptr->next;
    }
    cout<<endl;
    if(index == 0){
        cout<<"element is not present";
    }
    else{
        cout<<"Element present at the index: "<<index;
    }
}

Node* head = new Node;
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 10);
    insertAtEnd(head, 0);
    insertAtEnd(head, 34);
    insertAtEnd(head, 43);
    insertAtEnd(head, 38);

 linkedListTraversal(head);
    deleteAtEnd(head);
 cout<<endl<<"after deleteing the nodes"<<endl;
    linkedListTraversal(head);

    positionOfNode(head, 100);
return 0;
}