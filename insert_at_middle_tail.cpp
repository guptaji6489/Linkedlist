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

void insertatmiddle(node*&head,int data,int pos)
{
    if(head==NULL || pos==0)
        insertathead(head,data);
    else if(pos>length(head))
    {
        insertattail(head,data);
    }
    else{
        int jump = 1;
        node*temp = head;
        while(jump<=pos-1)
        {
            temp = temp->next;
            jump += 1;

        }
        node* n = new node(data);
        n->next=temp->next;
        temp->next=n;

    }


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
    insertattail(head,20);
    insertatmiddle(head,44,2);
    print(head);


}

