#include<iostream>
using namespace std;

struct Node{
     int data;
     struct Node*next;
};
void MultipliedLinkedlist(struct Node*ptr)
{
    while(ptr!=nullptr){
        cout<<ptr->data*10<<" ";
        ptr=ptr->next;
    }
}
//traversal of elements of linked list
void Traversal(struct Node*ptr){
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

}
int main(){
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*forth=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fifth=(struct Node*)malloc(sizeof(struct Node));
    struct Node*sixth=(struct Node*)malloc(sizeof(struct Node));
    struct Node*seventh=(struct Node*)malloc(sizeof(struct Node));
    struct Node*eighth=(struct Node*)malloc(sizeof(struct Node));
    struct Node*nineth=(struct Node*)malloc(sizeof(struct Node));
    struct Node*tenth=(struct Node*)malloc(sizeof(struct Node));

    head->data=2;
    head->next=second;

    second->data=7;
    second->next=third;

    third->data=9;
    third->next=forth;

    forth->data=44;
    forth->next=fifth;

    fifth->data=20;
    fifth->next=sixth;

    sixth->data=44;
    sixth->next=seventh;

    seventh->data=56;
    seventh->next=eighth;

    eighth->data=34;
    eighth->next=nineth;

    nineth->data=12;
    nineth->next=tenth;

    tenth->data=67;
    tenth->next=nullptr;
    cout<<"Traversal in linked list "<<endl;
    Traversal(head);
cout<<endl;
    MultipliedLinkedlist(head);


return 0;
}
