#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* push(Node* head,Node* tail,int val)
{
    Node *temp = new Node();
    temp->data = val;
    tail->next = temp;
    return tail = temp;
}

void printLinkedList(Node *head)
{
    while(head != 0x0)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}

Node* intersection(Node* head1,Node* head2)
{
    Node* head,*temp;
    head = temp = 0x0;

    while(head1 && head2)
    {
        while(head1 && head1->data < head2->data)
        {   
            head1 = head1->next;
        }
        while(head2 && head2->data < head1->data)
        {
            head2 = head2->next;
        }
        if(head1->data == head2->data)
        {
            if(head == 0x0)
            {
                head = new Node();
                head->data = head1->data;
                head->next = 0x0;
                temp = head;
            }else{
                Node*t = new Node();
                t->data = head1->data;
                t->next = 0x0;
                temp->next = t;
                temp = t;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return head;
}

int main()
{
    Node *head1,*tail1;
    head1 = tail1 = 0x0;

    head1 = new Node();
    head1->data = 1;
    head1->next = tail1;

    tail1 = head1;

    tail1 = push(head1,tail1,2);
    tail1 = push(head1,tail1,3);
    tail1 = push(head1,tail1,4);
    tail1 = push(head1,tail1,5);
    tail1 = push(head1,tail1,6);
    tail1 = push(head1,tail1,7);
    tail1 = push(head1,tail1,8);
    tail1 = push(head1,tail1,9);
    tail1 = push(head1,tail1,10);

    Node *head2,*tail2;
    head2 = tail2 = 0x0;

    head2 = new Node();
    head2->data = 4;
    head2->next = tail2;

    tail2 = head2;

    tail2 = push(head2,tail2,6);
    tail2 = push(head2,tail2,9);
    
    Node *intersection_head = intersection(head1,head2);
    printLinkedList(intersection_head);   

    return 0;
}