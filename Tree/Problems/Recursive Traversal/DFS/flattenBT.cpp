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
void traverse(TreeNode *root, vector<int> &ans){
    if(root == NULL) return;
    ans.push_back(root->data);
    traverse(root->left, ans);
    traverse(root->right, ans);
}
void construct(TreeNode* root, vector<int> &ans){
    for (int i = 1; i < ans.size(); i++)
    {   cout<<ans[i];
        root->left = NULL;
        root->right  =  createNode(ans[i]);
        root = root->right;
    }
    
}
void flatten(TreeNode *root)
{
    vector<int> ans;
    traverse(root, ans);
    construct(root, ans);
}
// void traverse(TreeNode *root, TreeNode *node){
//     if(root == NULL) return;

//     node = createNode(root->data);
//     node->left = NULL;

//     traverse(root->left, node->right);
//     traverse(root->right, node->right);
// }
// void flatten(TreeNode *root)
// {
//     TreeNode * node = createNode(root->data);
//     node->left = NULL;

//     traverse(root->left, node->right);
    
// }

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
     flatten(root);
    return 0;
}