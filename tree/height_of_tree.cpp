#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int height(TreeNode* root) {
    if(root==NULL)return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);
    return max(lheight,rheight)+1;
}
int diameter(TreeNode *root)
{
    if(root==NULL)return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);
    int currDiameter=lheight+rheight+1;
    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);
    return max(currDiameter,max(lheight,rheight));
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
    root->left->left->right=new TreeNode(8);
    cout<<"height : "<<height(root)<<endl;
    cout<<"diameter : "<<diameter(root)<<endl;
    return 0;
}