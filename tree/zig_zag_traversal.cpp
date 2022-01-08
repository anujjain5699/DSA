#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
vector<int> zigzagTraversal(Node* root)
{
    deque<Node*> q;
    vector<int> v;
    q.push_back(root);
    v.push_back(root->data);
    int l=1;
    Node* temp;
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            if(!(l&1))
            {
                temp=q.back();
                q.pop_back();
            }
            else
            {
                temp=q.front();
                q.pop_back();
            }
            if(!(l&1))
            {
                if(temp->right)
                {
                    q.push_back(temp->right);
                    v.push_back(temp->right->data);
                }
                if(temp->left)
                {
                    q.push_back(temp->left);
                    v.push_back(temp->left->data);
                }
            }
            else
            {
                if(temp->left)
                {
                    q.push_front(temp->left);
                    v.push_back(temp->left->data);
                }
                if(temp->right)
                {
                    q.push_front(temp->right);
                    v.push_back(temp->right->data);
                }
            }
        }
        l++;
    }
    return v;
}
int main()
{
    struct Node* root =new Node(1);
    root->left =new Node(2);
    root->right =new Node(3);
    root->left->left =new Node(7);
    root->left->right =new Node(6);
    root->right->left =new Node(5);
    root->right->right =new Node(4);
    vector<int> v=zigzagTraversal(root);
    for (int i = 0; i < v.size();i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
