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

node* middle(node*&head)
{
    node* fast=head;
    node* slow=head;
    while(fast->next!=NULL and fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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


int main()
{
    node*head = NULL;
    insertathead(head,5);
    insertathead(head,9);
    insertathead(head,1);
    insertathead(head,7);
        insertathead(head,22);

    print(head);
    node* mid = middle(head);
    cout<<mid->data;

}

