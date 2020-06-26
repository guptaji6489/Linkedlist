#include<bits/stdc++.h>
using namespace std;

class opeartions
{
public:
    int data;
    opeartions* next;

    opeartions(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};
// insert at the begining
void insertAtHead(opeartions* &head,int data)
{
    opeartions* n = new opeartions(data);
    n->next = head;
    head = n;
}

// insert at the last
void insertAtTail(opeartions* &head,int data)
{
    if (head == NULL) {
		// no node inside the linked list
		// no difference between insert at head and tail
		insertAtHead(head, data);
		return;
	}
    opeartions* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    opeartions* n = new opeartions(data);
    temp->next = n;



}
// calculating length of linkedlist

int length1(opeartions* head)
{
    int l=0;
    opeartions* temp = head;
    while(temp!=NULL)
    {
        temp = temp->next;
        l = l+1;
    }
    return l;
}

// insert at the middle
void insertAtMiddle(opeartions* &head,int data,int pos)
{
    if(head==NULL || pos==0)
        insertAtHead(head,data);
    else if(pos>length1(head))
    {
        insertAtTail(head,data);
    }
    else{
    int jump = 1;
    opeartions* temp = head;
    while(jump<pos-1)
    {
        temp = temp->next;
        jump = jump +1;
    }
    opeartions* n = new opeartions(data);
     n->next=temp->next;
     temp->next = n;

}
}

void deletefromhead(opeartions* &head)
{
    //EDGE CASE
	if (head == NULL) {
		return;
	}
    opeartions* temp =head;
    head = head->next;
    delete temp;
}

void deletefromtail(opeartions* head)
{
    if (head == NULL) {
		return;
	}

	if (head->next == NULL) { // there is only 1 node in my linked list
		deletefromhead(head);
		return;
	}

    opeartions* temp = head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    opeartions* tobedeleted = temp->next;
    temp->next = NULL;
	delete tobedeleted;
}

void deletefrommiddle(opeartions* head,int pos)
{
    int jump=1;
    opeartions* temp=head;
    while(jump<pos-1)
    {
        temp =temp->next;
        jump = jump+1;
    }
    opeartions* tobedeleted = temp->next->next;
    temp->next = temp->next->next;
    delete tobedeleted;
    return;


}

int searching(opeartions* head , int key)
{
    opeartions* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == key)
            return true;
        else
            temp=temp->next;
    }
    return false;
}


void print(opeartions* head)
{
    opeartions* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    opeartions* head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,1);
    insertAtHead(head,8);
    insertAtHead(head,6);
    cout<<"INSERTING AT BEGINING"<<endl;
    print(head);
    insertAtTail(head,20);
    insertAtTail(head,25);
    cout<<"INSERTING AT END"<<endl;
    print(head);
    insertAtMiddle(head,100,2);
    insertAtMiddle(head,99,4);
    cout<<"INSERTING AT MIDDLE"<<endl;
    print(head);
    deletefromhead(head);
    cout<<"deleting from head"<<endl;
    print(head);
    deletefromtail(head);
    cout<<"deleting from tail"<<endl;
    print(head);
    deletefrommiddle(head,3);
    cout<<"deleting from middle::"<<endl;
    print(head);
    cout<<"searching in a linkedlist"<<endl;
    cout<<searching(head,8);





}
