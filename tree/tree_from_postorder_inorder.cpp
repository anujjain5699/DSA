#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* preintree(vector<int>&preorder,int psi,
                        int pei,vector<int>&inorder,int isi,int iei)
    {
        if(isi>iei)return nullptr;
        TreeNode* root=new TreeNode(preorder[pei]);
        int inx=isi;
        while(inorder[inx]!=preorder[pei])inx++;
        int count=inx-isi;
        root->left=preintree(preorder,psi,psi+count-1,inorder,isi,inx-1);
        root->right=preintree(preorder,psi+count,pei-1,inorder,inx+1,iei);
        
        
        return root;
    }
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return preintree(preorder,0,n-1,inorder,0,n-1);
    }

void printCurrentLevel(TreeNode* root, int level);
int height(TreeNode* node);  
void printLevelOrder(TreeNode* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
/* Print nodes at a current level */
void printCurrentLevel(TreeNode*  root, int level)
{
    if (root == NULL)
        {
            cout<<"null ";
            return;
        }
    if (level == 1)
        cout << root->val << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(TreeNode*  node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}
int main()
{
    vector<int> preorder={9,15,7,20,3};
    vector<int> inorder={9,3,15,20,7};
    TreeNode* root=buildTree(preorder,inorder);
    printLevelOrder(root);
    return 0;
}