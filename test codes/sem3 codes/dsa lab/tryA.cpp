#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* f = NULL;
Node* r = NULL;

void Traversal(Node* head){
    Node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int isFull(Node* ptr){
    Node* n = new Node;
    if(n == NULL){
        return 1;
    }
    return 0;
}

void Enqueue(int data){
    Node* n = new Node;
    if(isFull(n)){
        cout<<"Queue if full";
        return;
    }
    n->data = data;
    n->next = NULL;
    if(f == NULL){
        f = r = n;
    }
    else{
        r->next = n;
        r = n;
    }
}

int Dequeue(){
    Node* ptr;
    int n;
    if(f == NULL){
        cout<<"Queue is empty";
        return -1;
    }
    else{
        ptr = f;
        n = ptr->data;
        f = f->next;
        delete ptr;
    }
    return n;
}

int main(){
    Enqueue(1);
    Enqueue(1);
    Enqueue(1);
    Enqueue(12);
    Dequeue();
    Traversal(f);
return 0;
}



