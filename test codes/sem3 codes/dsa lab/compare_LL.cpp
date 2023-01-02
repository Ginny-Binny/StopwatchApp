#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};
Node* removeLeadingZeros(struct Node* a)
{
	if (a != NULL && a->data == 0)
		return removeLeadingZeros(a->next);
	else
		return a;
}

int getSize(struct Node* a)
{
	int sz = 0;
	while (a != NULL) {
		a = a->next;
		sz++;
	}
	return sz;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}


int compare(struct Node* a,
			struct Node* b)
{

	
	a = removeLeadingZeros(a);
	b = removeLeadingZeros(b);

	int lenA = getSize(a);
	int lenB = getSize(b);

	if (lenA > lenB) {

		return 1;
	}
	else if (lenB > lenA) {
		return -1;
	}

	while (a != NULL && b != NULL) {
		if (a->data > b->data)
			return 1;
		else if (a->data < b->data)
			return -1;

		a = a->next;
		b = b->next;
	}

	return 0;
}

int main()
{
	
	struct Node* a = NULL;
	push(&a, 7);
	push(&a, 6);
	push(&a, 5);
    

	struct Node* b = NULL;
	push(&b, 3);
	push(&b, 3);
	push(&b, 2);

	cout << compare(a, b);

	return 0;
}
