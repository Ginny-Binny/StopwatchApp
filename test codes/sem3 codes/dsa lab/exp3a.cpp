#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node*next;
    node(int val)
    {
        this->data=val;
        next =NULL;
    }
};

void insert_end(node *head, int val)
{
    node *n =new node(val);
    if(head == NULL)
    {
        head=n;
        return;
    }

    node *temp =head;
    while(temp->next !=NULL)
    temp = temp-> next;
    temp->next=n;
}

void occurance( node *root, int val)
{
    int ans=0;
    node *temp= root;
    while (temp)
    {
        if (temp->data ==val)
        ans++;
        temp = temp ->next;
        }

        cout<<"Occurence of " << val <<" is " << ans <<" times "<<endl;

}

int main()
{
    int val;
    cout<<"Enter the number:";
    cin>>val;
    node *head =new node(1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    insert_end(head, 4);
    insert_end(head, 2);
    insert_end(head, 1);
    insert_end(head, 2);
    insert_end(head, 5);
    insert_end(head, 6);
    insert_end(head, 5);
    insert_end(head, 6);
    insert_end(head, 5);
    insert_end(head, 5);
    insert_end(head, 5);
    insert_end(head, 4);
    insert_end(head, 4);
    insert_end(head, 5);
    insert_end(head, 3);
    insert_end(head, 6);
    insert_end(head, 2);
    occurance(head , val);
    return 0;


}