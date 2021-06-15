#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
void sumreplace(Node* root)
{
    if(root == nullptr) return;
    sumreplace(root->left);
    sumreplace(root->right);
    if(root->left!=nullptr)root->val+=root->left->val;
    if(root->right!=nullptr)root->val+=root->right->val;
}
void preorder(Node* root)
{
    if(root==NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->right=new Node(8);
    preorder(root);
    cout<<endl;
    sumreplace(root);
    preorder(root);
    return 0;
}