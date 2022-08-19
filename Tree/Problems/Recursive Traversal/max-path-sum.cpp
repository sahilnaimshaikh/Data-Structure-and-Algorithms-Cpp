


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
int traverse(TreeNode* root , int &maxi) {
        if(root==NULL) return 0;

        int leftSum = traverse(root->left, maxi);
        int rightSum = traverse(root->right, maxi);
        
        maxi = max(maxi, leftSum+rightSum+root->data);

        return max(leftSum, rightSum)+root->data <0 ? 0 : max(leftSum, rightSum)+root->data ;

    }
int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        traverse(root, maxi);
        return maxi;
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
    cout<<maxPathSum(root);
    return 0;

//         2
//     3       5
// 35    4     
}