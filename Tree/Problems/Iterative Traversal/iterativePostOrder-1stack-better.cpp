#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createNode(int data)
{
    struct TreeNode *treeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}

vector<int> iterativePostOrderTraversal(TreeNode *root)
{
    vector<int> st2;
    if(root == NULL) return st2;
    stack<TreeNode*> st1;
    
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push_back(root->data);
        if(root->left != NULL)st1.push(root->left);
        if(root->right != NULL)st1.push(root->right);
    }
    
     reverse(st2.begin(), st2.end());
     return st2;
}

int main()
{
     struct TreeNode *root = createNode(2);
    struct TreeNode *leftChild = createNode(3);
    struct TreeNode *rightChild = createNode(5);
    struct TreeNode *leftChild_left = createNode(35);
    struct TreeNode *leftChild_right = createNode(4);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
    for(auto it : iterativePostOrderTraversal(root))cout<<it<<" ";
    return 0;
}