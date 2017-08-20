#include <bits/stdc++.h>

using namespace std;

struct Node{
    char data;
    Node* next;
};

Node* push(Node* head,Node* tail,char c)
{
    Node *temp = new Node();
    temp->data = c;
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

bool compare(Node* head1,Node* head2)
{
    while(head1 && head2)
    {
        if(head1->data != head2->data)
            return 0;
        else{
            head1 = head1->next,head2 = head2->next;
        }
    }
    return 1;
}

bool palin(Node* head)
{
    if(head->next == 0x0)
        return 1;
    Node *slow = head,*fast = head->next;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *tmp = slow->next;
    slow->next = 0x0;
    tmp = reverse(tmp);

    if(compare(head,tmp))
    {
        tmp = reverse(tmp);
        slow->next = tmp;
        return 1;
    }else{
        tmp = reverse(tmp);
        slow->next = tmp;
        return 0;
    }
}

int main()
{
    Node *head,*tail;
    head = tail = 0x0;

    head = new Node();
    head->data = 'a';
    head->next = tail;

    tail = head;

    tail = push(head,tail,'b');
    tail = push(head,tail,'a');
    tail = push(head,tail,'x');
    // tail = push(head,tail,'c');
    tail = push(head,tail,'c');
    tail = push(head,tail,'c');
    tail = push(head,tail,'a');
    tail = push(head,tail,'b');
    tail = push(head,tail,'a');

    printLinkedList(head);

    if(palin(head))
    {
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    printLinkedList(head);
    return 0;
}