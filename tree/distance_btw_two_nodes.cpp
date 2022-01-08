#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
Node* findLCA2(Node* root,int n1,int n2)
{
    if(root == nullptr)return nullptr;
    if(root->val==n1 || root->val==n2)return root;
    Node* left_lca=findLCA2(root->left,n1,n2);
    Node* right_lca=findLCA2(root->right,n1,n2);
    if(left_lca && right_lca)return root;
    if(left_lca==nullptr && right_lca==nullptr)return nullptr;
    return (left_lca!=nullptr)?left_lca:right_lca;
}
int findDistance(Node* root,int key,int dis)
{
    if(root==nullptr)return -1;
    if(root->val==key)return dis;
    int left=findDistance(root->left,key,dis+1);
    if(left!=-1)return left;
    return findDistance(root->right,key,dis+1);
}
int findDistwoNodes(Node* root,int n1,int n2)
{
    Node* lca=findLCA2(root,n1,n2);
    int d1=findDistance(root,n1,0);
    int d2=findDistance(root,n2,0);
    return d1+d2;
}
int main()
{
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->right = new Node(9);
    root->right->right = new Node(7);
    cout<<findDistwoNodes(root,2,9);
    return 0;
}