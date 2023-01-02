#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val)
    {
        this->data =val;
        next = NULL;
    }
};

void insert_end(node *head, int val)
{
    node *n = new node(val);
    if( head == NULL)
    {
        head =n;
        return;
    }

    node *temp = head;
    while( temp -> next !=NULL)
    temp->next=n;
}

void display(node *head)
{
    node *temp =head;
    while (temp !=NULL)
    {
        cout<< temp->data<<" ->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

void multiply(node *&root)
{
    node *temp =root;
    while (temp)
    {
        temp->data *= 10;
        temp = temp->next;

    }
}

int main()
{
    node *head = new node (1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    multiply(head);
    display(head);
    return 0;
}