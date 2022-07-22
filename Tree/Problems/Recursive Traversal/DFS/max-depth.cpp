


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
    return max(leftTree, rightTree)+1;
    
}

// void traverse(TreeNode *root, int count, int &max){
//     if(root == NULL) return ;
//     if(count >= max) max = count;
//     // count++;
//     traverse(root->left, count++, max);
//     traverse(root->right, count++, max);  
// }
// int maxDepth(TreeNode *root)
// {   
//     if(root == NULL)return 0;
    
//     int count = 1;
//     int max = 1;
//     traverse(root, count, max);
//     return max;
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
    cout<<maxDepth(root);
    return 0;
}