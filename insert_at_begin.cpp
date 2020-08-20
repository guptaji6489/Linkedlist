#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        this->data = d;
        this->next=NULL;

    }
};
void insertathead(node*&head,int data)// yaha pe hum ussi head me changes kr rehe
{
    node* n = new node(data);
    n->next=head;
    head=n;
}
void print(node*head) // yaha pe head ki copy bana ke print krwa rahe
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
    print(head);


}
