
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
int  length(node*head)
{
    int len = 0;
    while(head!=NULL)
    {
        head = head->next;
        len +=1;
    }
    return len;
}

void insertattail(node*&head,int data)
{
    if(head==NULL)
    {
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL)
    {
        tail = tail->next;

    }
    tail->next = new node(data);
    return;
}


void print(node*head)
{
    while(head->next!=NULL)
    {
        cout<<head->data;
        head = head->next;
    }
    cout<<head->data +1;
    cout<<endl;
}


int main()
{
    node*head = NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    //insertattail(head,20);//tail

    print(head);


}

