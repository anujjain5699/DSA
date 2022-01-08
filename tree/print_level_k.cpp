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
void printAtLevelK(TreeNode<int>*root,int k){
    if(root==NULL) return;
    if(k==0) cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
    return;
}
int main(){
    TreeNode<int>* root=takeInputLevelWise();
    printAtLevelK(root,2);
    return 0;
}