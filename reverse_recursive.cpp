#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data = d;
        next=NULL;

    }
};
void insertathead(node*&head,int data)
{
    node* n = new node(data);
    n->next=head;
    head=n;
}
void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<endl;
}


node* reverseRecursive(node* head) {
	// BASE CASE.
	if (head == NULL or head->next == NULL) {
		return head;
	}

	node* newHead = reverseRecursive(head->next);

	// my Work
	node* curr = head;
	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
}

int main()
{
    node*head = NULL;
    insertathead(head,5);
    insertathead(head,9);
    insertathead(head,1);
    insertathead(head,7);
    print(head);
    head = reverseRecursive(head);
    print(head);

}

