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

Node* mergeSort(Node* head)
{
    if(head == 0x0 || head->next == 0x0)
        return head;

    Node* slw = head,*fst = head->next;

    while(slw && fst && fst->next)
    {
        slw = slw->next;
        fst = fst->next->next;
    }

    Node* right = slw->next;
    slw->next = 0x0;

    Node *left = mergeSort(head);
    right = mergeSort(right);

    Node* tmp;

    if(left->data < right->data)
    {
        head = left;
        tmp = left;
        left = left->next;
    }else{
        head = right;
        tmp = right;
        right = right->next;
    }

    while(left && right)
    {
        if(left->data < right->data)
        {
            tmp->next = left;
            left = left->next;
        }else{
            tmp->next = right;
            right = right->next;
        }
        tmp = tmp->next;
    }

    if(left)
    {
        tmp->next = left;
    }else if(right)
    {
        tmp->next = right;
    }
    return head;
}


int main()
{
    Node *head,*tail;
    head = tail = 0x0;

    head = new Node();
    head->data = 10;
    head->next = tail;

    tail = head;

    tail = push(head,tail,9);
    tail = push(head,tail,8);
    tail = push(head,tail,7);
    tail = push(head,tail,6);
    tail = push(head,tail,5);
    tail = push(head,tail,4);
    tail = push(head,tail,3);
    tail = push(head,tail,2);
    tail = push(head,tail,1);

    cout << "Before Sorting\n";
    printLinkedList(head);

    head = mergeSort(head);

    cout << "After Sorting\n";
    printLinkedList(head);

    return 0;
}