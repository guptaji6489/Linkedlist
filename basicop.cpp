#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node*next;

node(int data)
{
    this->data=data;
    this->next=NULL;
}
};


void insertathead(node*&head,int data)
{
    node*n = new node(data);
    n->next=head;
    head=n;

}

void insertatend(node*head,int data)
{
    if(head==NULL)
    {
        insertathead(head,data);
        return;
    }
    node*temp=head;
     while(temp->next != NULL)
    {
        temp=temp->next;
    }
    node*n = new node(data);
    temp->next=n;

}

void insertatmiddle(node*head,int data,int key)
{
    if(head==NULL  || key==0)
    {
        insertathead(head,data);
        return;
    }
    node*temp=head;
    int j=1;
    while(j<key-1)
    {
        temp=temp->next;
        j++;
    }
    node*n = new node(data);
    n->next=temp->next;
    temp->next=n;
}


void print(node*head)
{
    node*temp = head;
    while(temp != NULL)
    {
        cout<<temp->data <<" -> ";
        temp=temp->next;
    }
}

int length(node*head)
{
    if(head==NULL)
    {
        return 0;
    }
    int l=0;
    node*temp = head;

    while(temp != NULL)
    {
       l++;
        temp=temp->next;
    }
    return l;
}

void deletefromhead(node *&head)
{
     if(head==NULL)
    {
        return;
    }
    node*temp = head;
    head=temp->next;
    delete temp;


}

void deletefromtail(node *head)
{
     if(head==NULL)
    {
        return;
    }
    if (head->next == NULL) { // there is only 1 node in my linked list
		deletefromhead(head);
		return;
	}
     node*temp = head;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    node*tobedeleted = temp->next;
    temp->next=NULL;
    delete tobedeleted;


}


void deletefrommiddle(node*head,int key)
{
    if(head==NULL  || key==0)
    {
        return;
    }
    node*temp=head;
    int j=1;
    while(j<key-1)
    {
        temp=temp->next;
        j++;
    }
    node*tobedeleted = temp->next;
    temp->next=temp->next->next;
    delete tobedeleted;
}


node* reverselink(node*&head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node*newnode = reverselink(head->next);
    node*curr=head;
    curr->next->next=curr;
    curr->next=NULL;
    return newnode;
}

node* reverseite(node*&head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    node*newnode =NULL;
    node*curr=head;
    while(curr!=NULL)
    {
        node*n=curr->next;
        curr->next=newnode;
        newnode=curr;
        curr=n;
    }

    return newnode;
}

node * findmiddle(node*head)
{
    node*slow=head;
    node*fast=head;
    if(head->next!=NULL && head->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}


int main()
{
    node*head=NULL;
    insertathead(head,5);
    insertathead(head,6);
    insertathead(head,7);
    insertathead(head,9);
    insertathead(head,10);
    cout<<"after inserting at head "<<endl;;
    print(head);
    cout<<endl;

    insertatend(head,4);
    cout<<"after inserting at end "<<endl;;
    print(head);
    cout<<endl;

    insertatmiddle(head,8,4);
    cout<<"after inserting at middle "<<endl;
    print(head);
    cout<<endl;

    int l = length(head);
    cout<<"length of a linklist "<<endl<<l<<endl;

    deletefromhead(head);
    cout<<"after deleting from head "<<endl;
    print(head);
    cout<<endl;

    deletefromtail(head);
    cout<<"after deleting from tail "<<endl;
    print(head);
    cout<<endl;

    deletefrommiddle(head,4);
    cout<<"after deleting from middle "<<endl;
    print(head);
    cout<<endl;

    head=reverselink(head);
    cout<<"after reverse recursive "<<endl;
    print(head);
    cout<<endl;

    head=reverseite(head);
    cout<<"after reverse iterative "<<endl;
    print(head);
    cout<<endl;

    node*m;
    m=findmiddle(head);
    cout<<"middle element is " <<m->data<<endl;
    cout<<endl;





    return 0;
}
