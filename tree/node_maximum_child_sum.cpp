#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root==NULL)return NULL;
    TreeNode<int>* maxNode=NULL;
    queue<TreeNode<int>*> pending;
    int max=0;
    pending.push(root);
    while(pending.size()!=0){
        TreeNode<int>* front=pending.front();
        pending.pop();
        int curr=front->data;
        for(int i=0;i<front->children.size();i++){
            curr+=front->children[i]->data;
            pending.push(front->children[i]);
        }
        if(curr>max){
            max=curr;
            maxNode=front;
        }
    }
    return maxNode;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}