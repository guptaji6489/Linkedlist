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
void removedup(node*head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }

        temp = temp->next;
    }
    return;
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
    insertathead(head,2);
    insertathead(head,2);
    insertathead(head,4);
    insertathead(head,5);
    insertathead(head,5);
    print(head);
    removedup(head);
    print(head);
}

