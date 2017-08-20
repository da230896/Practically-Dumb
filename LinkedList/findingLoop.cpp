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

Node* reverse(Node *head)
{
    Node* prev = 0x0;
    while(head->next != 0x0)
    {
        Node *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    head->next = prev;
    return head;
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


int main()
{
    Node *head,*tail;
    head = tail = 0x0;

    head = new Node();
    head->data = 1;
    head->next = tail;

    tail = head;

    tail = push(head,tail,2);
    tail = push(head,tail,3);
    tail = push(head,tail,4);
    tail = push(head,tail,5);
    tail = push(head,tail,6);
    tail = push(head,tail,7);
    tail = push(head,tail,8);
    tail = push(head,tail,9);
    tail = push(head,tail,10);

    //tail->next = head->next->next->next;
    Node *temp = reverse(head);

    if(temp == head)
        cout << "Loop Found\n";
    else{
        head = temp;
        cout << "No Loop Found\n";
    }

    return 0;
}