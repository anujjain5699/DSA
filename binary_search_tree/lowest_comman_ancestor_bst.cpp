#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
    
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

/*
Method 1 finds LCA in O(n) time but requires three tree traversals 
plus extra spaces for path arrays. If we assume that the
keys n1 and n2 are present in Binary Tree, 
we can find LCA using a single traversal of Binary Tree
and without extra storage for path arrays. 
*/
bool findpath(BinaryTreeNode<int>* root,vector<int> &path,int k)
{
    if(root == NULL) return false;
    path.push_back(root->data);
    if(root->data == k)return true;
    if((root->left != NULL && findpath(root->left,path,k)) || 
    (root->right != NULL && findpath(root->right,path,k)))
    return true;
    path.pop_back();
    return false;

}
int getLCA(BinaryTreeNode<int>* root , int n1 , int n2){
    if(root == NULL)return -1;
    vector<int> v1, v2;
    if(!findpath(root,v1,n1) || !findpath(root,v2,n2))
    return -1;
    int i;
    for(i=0;i<v1.size() && v2.size();i++)
    if(v1[i]!=v2[i])break;
    return v1[i-1];
}

/*
method 2 assumes that keys are present in Binary Tree. If one key
is present and the other is absent, then it returns the present 
key as LCA (Ideally should have returned NULL). 
*/
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root==NULL)return -1;
    if(root->data==a || root->data==b)return root->data;
    int leftoutput=getLCA(root->left, a, b);
    int rightoutput=getLCA(root->right, a, b);
    if(leftoutput==rightoutput)return leftoutput;
    else if(rightoutput==-1)return leftoutput;
    else if(leftoutput==-1)return rightoutput;
    else return root->data;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}