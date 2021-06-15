#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void levelordertraversal(TreeNode* root)
{
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        if(node!=NULL)
        {
            cout<<node->val<<" ";
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    levelordertraversal(root);
    return 0;
}