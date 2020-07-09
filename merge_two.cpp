#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int d)
    {
        val = d;
        next=NULL;

    }
};
ListNode* merge(ListNode* a, ListNode* b) {
	//BASE CASE
	if (a == NULL) {
		return b;
	}

	if (b == NULL) {
		return a;
	}

	ListNode* newHead;

	if (a->val < b->val) {
		newHead = a;
		newHead->next = merge(a->next, b);
	} else {
		newHead = b;
		newHead->next = merge(a, b->next);
	}

	return newHead;
}
void insertAtTail(ListNode*&head,int data)
{
    if(head==NULL)
    {
        head = new ListNode(data);
        return;
    }
    ListNode*tail = head;
    while(tail->next!=NULL)
    {
        tail = tail->next;

    }
    tail->next = new ListNode(data);
    return;
}
void display(ListNode*head)
{
    while(head!=NULL)
    {
        cout<<head->val<<"-->";
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    ListNode* head1 = NULL;
    insertAtTail(head1, 1);
	 insertAtTail(head1, 3);
	 insertAtTail(head1, 5);
	 insertAtTail(head1, 8);
	 insertAtTail(head1, 9);

	 ListNode* head2 = NULL;

	 insertAtTail(head2, 2);
	 insertAtTail(head2, 4);
	 insertAtTail(head2, 6);
	 insertAtTail(head2, 7);

	 cout << "First Linked List ******************" << endl;
	 display(head1);

	 cout << "Second Linked List ******************" << endl;
	 display(head2);

	 ListNode* mergedList = merge(head1, head2);

	cout << "Merged Linked List ******************" << endl;
	 display(mergedList);



}

