#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
int height(Node* root)
{
    if(root ==NULL) return 0;
    int lheight =height(root->left);
    int rheight =height(root->right);
    return max(lheight,rheight)+1;
}
/*
For the current node root, calling height() for its left and right children actually 
has to access all of its children, thus the complexity is O(N). We do this for each 
node in the tree, so the overall complexity of isBalanced
will be O(N^2). This is a top down approach.
*/
bool isbalanced(Node* root)
{
    if(root == NULL) return true;
    if(isbalanced(root->left)==false) return false;
    if(isbalanced(root->right)==false) return false;
    int lheight =height(root->left);
    int rheight =height(root->right);
    if(abs(lheight-rheight)<=1)return true;
    else return false;
}
/*
The second method is based on DFS. Instead of calling height()
 explicitly for each child node, we return the height of the current node in DFS recursion.
  When the sub tree of the current node (inclusive) is balanced, the function dfsHeight() 
  returns a non-negative value as the height. Otherwise -1 is returned. According to the 
  leftHeight and rightHeight of the two children, the parent node could check if the sub tree
is balanced, and decides its return value.
*/
int dfsHeight (Node *root)
{
        if (root == NULL) return 0;

        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
}
bool isBalanced_without_height(Node *root)
{
    return dfsHeight (root) != -1;
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
    root->left->left->right->right=new Node(9);
    cout<<"Method 1: \n";
    if(isbalanced(root))cout<<"Height Balanced Binary Tree";
    else cout<<"Height Unbalanced Binary Tree";
    cout<<"\nMethod 2: \n";
    if(isBalanced_without_height(root))cout<<"Height Balanced Binary Tree";
    else cout<<"Height Unbalanced Binary Tree";
    return 0;
}