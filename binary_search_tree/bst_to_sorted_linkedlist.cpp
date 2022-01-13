/*
Code: BST to Sorted LL

Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:

The first and only line of input contains data of the nodes of the tree in level order form.
The data of the nodes of the tree is separated by space. If any node does not have left 
or right child, take -1 in its place. Since -1 is used as an indication whether the left 
or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:

The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10


*/
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	if(root==NULL)return NULL;
    if(root->left==NULL && root->right==NULL){
        Node<int>* output=new Node<int>(root->data);
        return output;
    }
    Node<int>* output = new Node<int>(root->data);
    Node<int>* leftOutput = constructLinkedList(root->left);
    Node<int>* rightOutput = constructLinkedList(root->right);
    if(leftOutput!=NULL){
        Node<int>* temp=leftOutput;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=output;
    }
    output->next=rightOutput;
    if(leftOutput==NULL){
        return output;
    }
    return leftOutput;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}