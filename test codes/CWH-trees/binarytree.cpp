#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;

};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n=(struct node *) malloc(sizeof(struct node));
    n->data=data; // setting the data
    n->left=NULL; // setting the left and right child to NULL
    n->right=NULL; // finally returning the created node
    return n;
}



int main(){

//Constructing thee root node-Using function
struct node *p = createNode(4);
struct node *p1= createNode(1);
struct node *p2= createNode(6);

//Finally tree looks like this :
//     4
//    / \ 
//   1   6


//linking the root node with left and right children 
p->left=p1;
p->right=p2;

return 0;

}