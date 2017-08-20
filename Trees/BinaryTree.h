
using namespace std;

/*

This is our required TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0x0), right(0x0) {}
};
and DLL will have this structure
    struct node
    {
        int key;
        struct node *left;
        struct node *right;
    };

*/

void convertToDLL(TreeNode* root,TreeNode *head,TreeNode *tail)
{
    //while we are doing inorder traversal we are converting into DLL
    if(root == 0x0)
        return;

    convertToDLLUtil(root->left,head,tail);
    root->left = tail;

    if(head)
    {
        tail->right = root;
    }else{
        head = root;
    }
    tail = root;
    
    convertToDLL(root->right,head,tail);
}
