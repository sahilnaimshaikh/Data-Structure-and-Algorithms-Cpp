


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
  bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        targetSum-=root->data;
        if(targetSum == 0 && !root->left && !root->right) return true;

        if(hasPathSum(root->left, targetSum)) return true;
        if(hasPathSum(root->right, targetSum)) return true;

        return false;

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
    cout<<hasPathSum(root, 7);
    return 0;

//         2
//     3       5
// 35    4     
}