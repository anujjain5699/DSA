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

void printLevelWise(BinaryTreeNode<int> *root) {
	if(root==NULL)return;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(q.size()!=0){
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        cout<<front->data<<":";
        if(front->left!=NULL){
            cout<<"L:"<<front->left->data;
            q.push(front->left);
        }
        else{
            cout<<"L:-1";
        }
        if(front->right!=NULL){
            cout<<",R:"<<front->right->data<<"\n";
            q.push(front->right);
        }
        else{
            cout<<",R:-1\n";
        }
    }
}

int height(BinaryTreeNode<int>* root){
    if(root==NULL)return 0;
    return 1+max(height(root->left),height(root->right));
}

int diameter(BinaryTreeNode<int>* root){
    if(root==NULL)return 0;
    int heightRoot=height(root->left)+height(root->right);
    int diameterLeft=diameter(root->left);
    int diameterRight=diameter(root->right);
    return max(heightRoot, max(diameterLeft, diameterRight));
}

pair<int, int> diameterOptimized(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int, int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>leftAns=diameterOptimized(root->left);
    pair<int,int>rightAns=diameterOptimized(root->right);
    int leftheight=leftAns.first;
    int rightheight=rightAns.first;
    int leftdiameter=leftAns.second;
    int rightdiameter=rightAns.second;
    int height=1+max(leftheight,rightheight);
    int diameter=max(leftheight+rightheight,max(rightdiameter,leftdiameter));
    pair<int,int>ans;
    ans.first = height;
    ans.second = diameter;
    return ans;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    cout<<"\ndiameter:"<<diameter(root);
}