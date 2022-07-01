


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
int maxDepth(TreeNode *root){
    if(root == NULL) return 0;
    
    int leftTree = maxDepth(root->left);
    int rightTree = maxDepth(root->right);

    if(leftTree == -1 || rightTree == -1) return -1;
    if(abs(leftTree-rightTree)>1) return -1;
    return max(leftTree, rightTree)+1;
    
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
    cout<<maxDepth(root);
    return 0;
}