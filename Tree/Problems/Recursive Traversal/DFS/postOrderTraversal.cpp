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
    traverse(root->left, ans);
    traverse(root->right, ans);
    ans.push_back(root->data);
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    traverse(root, ans);
    return ans;
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
    for(auto it : postorderTraversal(root))cout<<it<<" ";
    return 0;
}