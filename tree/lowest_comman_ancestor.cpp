#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool findpath(Node* root,vector<int> &path,int k)
{
    if(root == nullptr) return false;
    path.push_back(root->val);
    if(root->val == k)return true;
    if((root->left != nullptr && findpath(root->left,path,k)) || 
    (root->right != nullptr && findpath(root->right,path,k)))
    return true;
    path.pop_back();
    return false;

}
/*
Method 1 finds LCA in O(n) time but requires three tree traversals 
plus extra spaces for path arrays. If we assume that the
keys n1 and n2 are present in Binary Tree, 
we can find LCA using a single traversal of Binary Tree
and without extra storage for path arrays. 
*/
int findLCA1(Node* root,int n1,int n2)
{
    if(root == nullptr)return -1;
    vector<int> v1, v2;
    if(!findpath(root,v1,n1) || !findpath(root,v2,n2))
    return -1;
    int i;
    for(i=0;i<v1.size() && v2.size();i++)
    if(v1[i]!=v2[i])break;
    return v1[i-1];

}
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
/*
Note that the above method2 assumes that keys are present in Binary Tree. If one key
is present and the other is absent, then it returns the present 
key as LCA (Ideally should have returned NULL). 
*/
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
    cout<<"Method 1 :\n";
    cout << "LCA(4, 5) = " << findLCA1(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA1(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA1(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA1(root, 2, 4);
    cout << "\nLCA(6, 9) = " << findLCA1(root, 6, 9);
    cout<<"\nMethod 2 :\n";
    cout << "LCA(4, 5) = " << findLCA2(root, 4, 5)->val;
    cout << "\nLCA(4, 6) = " << findLCA2(root, 4, 6)->val;
    cout << "\nLCA(3, 4) = " << findLCA2(root, 3, 4)->val;
    cout << "\nLCA(2, 4) = " << findLCA2(root, 2, 4)->val;
    cout << "\nLCA(6, 9) = " << findLCA2(root, 6, 9)->val;
    return 0;
}