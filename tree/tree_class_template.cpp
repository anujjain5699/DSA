#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data = data;
    }
};
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0){
        TreeNode<int>* front=pendingNode.front();
        pendingNode.pop();
        cout<<"Enter num of children of "<<front->data<<"\n";
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<"\n";
            cin>>childData;
            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data: \n";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter num of children of "<<rootData<<"\n";
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printLevelWise(TreeNode<int>* root){
    if(root==NULL) return;
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0){
        cout<<pendingNode.front()->data<<":";
        TreeNode<int>* front=pendingNode.front();
        for(int i=0;i<front->children.size();i++){
            cout<<pendingNode.front()->children[i]->data;
            pendingNode.push(pendingNode.front()->children[i]);
            if(i<pendingNode.front()->children.size()-1){
                cout<<",";
            }
        }
        cout<<endl;
        pendingNode.pop();
    }
}

void printTree(TreeNode<int>* root) {
    if(root==NULL)return;
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<"\n";
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int countNodes(TreeNode<int>* root){
    if(root==NULL)return 0;
    int count=1;
    for(int i=0;i<root->children.size();i++){
        count+=countNodes(root->children[i]);
    }
    return count;
}
int treeSum(TreeNode<int>* root){
    if(root==NULL)return 0;
    int count=0;
    for(int i=0;i<root->children.size();i++){
        count+=treeSum(root->children[i]);
    }
    return count+root->data;
}
TreeNode<int>* maxNode(TreeNode<int>* root){
    if(root==NULL)return NULL;
    TreeNode<int>* max=root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* cur=root->children[i];
        if(cur>max)max=cur;
    }
    return max;
}
int main(){
    //TreeNode<int>* root=takeInput();
    TreeNode<int>* root=takeInputLevelWise();

    //print dfs
    //printTree(root);

    //print levelwise
    printLevelWise(root);

    //count number of nodes
    //cout<<countNodes(root);

    //sum of nodes of tree
    cout<<treeSum(root);
    return 0;
}