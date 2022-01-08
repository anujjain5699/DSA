#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<int> preorder(TreeNode* root){
    vector<int> preorder;
    if(root==NULL){return preorder;}
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preorder.push_back(root->val);
        if(root->right)st.push(root->right);
        if(root->left)st.push(root->left);
    }
    return preorder;
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
    vector<int>v=preorder(root);
    for(int i:v)cout<<i;
    return 0;
}