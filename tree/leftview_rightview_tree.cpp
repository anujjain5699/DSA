#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
void rightview(Node* root)
{
    if(root==nullptr) return;
    queue<Node*> q;
    int n;
    q.push(root);
    while(!q.empty())
    {
        n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(i==n-1)cout<<curr->val<<" ";
            if(curr->left!=nullptr)q.push(curr->left);
            if(curr->right!=nullptr)q.push(curr->right);
        }
    }
}
void leftview(Node* root)
{
    if(root==nullptr) return;
    queue<Node*> q;
    int n;
    q.push(root);
    while(!q.empty())
    {
        n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(i==0)cout<<curr->val<<" ";
            if(curr->left!=nullptr)q.push(curr->left);
            if(curr->right!=nullptr)q.push(curr->right);
        }
    }
}
int main()
{
    Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->left->left=new Node(16);
    root->right->left->left->left=new Node(15);
    root->right->left->left->right=new Node(12);
    root->right->right=new Node(7);
    root->left->left->right=new Node(8);
    root->left->left->right->right=new Node(9);
    root->left->left->right->right->left=new Node(18);
    cout<<"RightView : \n ";
    rightview(root);
    cout<<"\nLeftView : \n ";
    leftview(root);
    return 0;
}