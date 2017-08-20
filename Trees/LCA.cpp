#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

const int LOGMAX = 20;
const int MAXN = 1e5+1;
unordered_map<TreeNode*,int> L;
unordered_map<TreeNode*,vector<TreeNode*> > P;

int lca(TreeNode* A, int val1, int val2) {
    
    
}

void dfs(TreeNode* u,TreeNode* v,int lv = 0)
{
    
}

int main()
{



    return 0;
}