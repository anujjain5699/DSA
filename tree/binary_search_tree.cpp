#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
Node* bst(Node* root,int val)
{
    if(root==NULL) return new Node(val);
    if(val<root->data)
    {
        root->left=bst(root->left,val);
    }else{
        root->right=bst(root->right,val);
    }
    return root;
}
void print(Node* root)
{
    if(root==NULL) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main()
{
    Node* root = NULL;
    root=bst(root,5);
    bst(root,1);
    bst(root,3);
    bst(root,4);
    bst(root,2);
    bst(root,7);
    print(root);
    return 0;
}