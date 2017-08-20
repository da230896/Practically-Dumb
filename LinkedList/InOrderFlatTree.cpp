#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }

};
 
// Utility function for printing double linked list.
void printList(Node* head)
{
    printf("Extracted Double Linked list is:\n");
    while (head)
    {
        printf("%d ", head->data);
        head = head->right;
    }
}

// BToDLL and BToDLL1 are similar inorder traversal

void BToDLL(Node* root,Node **head)
{
    if(root == 0x0)
        return;

    BToDLL(root->right,head);

    root->right = *head;

    if((*head) != 0x0)
    {
        (*head)->left = root;
    }
    *head = root;

    BToDLL(root->left,head);

}

void BToDLL1(Node* root,Node** head)
{
    if(root == 0x0)
        return;
    static Node* prev = 0x0;

    BToDLL1(root->left,head);

    if(prev == 0x0)
    {
        *head = root;
    }else{
        root->left = prev;
        prev->right = root;
    }

    prev = root;
    BToDLL1(root->right,head);
}

void fixleft(Node* root)
{
    static Node* prev = 0x0;

    if(root)
    {
        fixleft(root->left);
        root->left = prev;
        prev = root;
        fixleft(root->right);
    }
} 

Node* fixRight(Node* root)
{
    while(root && root->right)
        root = root->right;

    Node *prev;
    while(root && root->left)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
    return root;
} 

void BToDLL2(Node* root,Node **head)
{
    fixleft(root);
    *head = fixRight(root);
    return;
}


// Driver program to test above function
int main()
{
    /* Constructing below tree
               5
             /   \
            3     6
           / \     \
          1   4     8
         / \       / \
        0   2     7   9  */
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(8);
    root->left->left->left = new Node(0);
    root->left->left->right = new Node(2);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(9);
 
    Node* head = NULL;
    //BToDLL(root, &head);
 
    // BToDLL2(root, &head);

    BToDLL1(root, &head);

    printList(head);
 
    return 0;
}