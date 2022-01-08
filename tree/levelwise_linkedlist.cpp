/*
Given a binary tree, 
write code to create a separate linked list for each level. 
You need to return the array which contains head of each level linked list.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printTreeLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL)return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()){
        if(q.front()==NULL){
            q.pop();
            if(q.empty())break;
            q.push(NULL);
            cout<<endl;
        }
        if(q.front()->left)q.push(q.front()->left);
        if(q.front()->right)q.push(q.front()->right);
        cout<<q.front()->data<<" ";
        q.pop();
    }
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> v;
    if(root==NULL){
        v.push_back(NULL);
        return v;
    }
    queue<BinaryTreeNode<int>*>q;
    Node<int>* head=NULL;
    Node<int>* tail=head;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        if(front==NULL){
            tail->next=NULL;
            if(q.empty())break;
            tail=NULL;
            head=NULL;
            q.push(NULL);
        }else{
            Node<int>* node=new Node<int>(front->data);
            if(head==NULL){
                head=tail=node;
                v.push_back(head);
            }
            else{
                tail->next=node;
                tail=tail->next;
            }
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
    }
    return v;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);
    printTreeLevelWise(root);
    cout<<"\nPrint linkedlist heads :\n";
    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}