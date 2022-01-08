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
   
Node* search(Node* root,int val)
{
    if(root==NULL)return NULL;
    if(root->data==val)return root;
    if(val<root->data)return search(root->left,val);
    else return search(root->right,val);
}
Node* deleteNode(Node* root,int val)
{
    if(root==NULL)return NULL;
    else if(val<root->data)
    {
        root->left= deleteNode(root->left,val);
        return root;
    }
    else if(val>root->data)
    {
        root->right= deleteNode(root->right,val);
        return root;
    }
    else{
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
            Node* replace=root->right;
            while(replace->left!=NULL)
            replace=replace->left;
            root->data=replace->data;
            root->right=deleteNode(root->right,replace->data);
            return root;
    }
}
void levelordertraversal(Node* root)
{
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();
        if(node!=NULL)
        {
            cout<<node->data<<" ";
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
        }
        else if(!q.empty())
        {
            cout<<endl;
            q.push(NULL);
        }
    }
}
int main()
{
    Node* root = NULL;
    root=bst(root,5);
    bst(root,3);
    bst(root,7);
    bst(root,1);
    bst(root,6);
    bst(root,8);
    levelordertraversal(root);
    cout<<"\n*****"<<endl;
    print(root);
    cout<<"\n*****"<<endl;
    root = deleteNode(root,7);
    levelordertraversal(root);
    cout<<"\n*****"<<endl;
    print(root);
    return 0;
}