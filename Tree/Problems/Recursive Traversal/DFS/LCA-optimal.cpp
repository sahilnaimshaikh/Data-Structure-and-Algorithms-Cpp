
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
 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2){
    if(root==NULL || root == node1 || root == node2){
        return root;
    }
    TreeNode * left = lowestCommonAncestor(root->left, node1, node2);
    TreeNode * right = lowestCommonAncestor(root->right, node1, node2);

    if(left == NULL)return right;
    else if(right == NULL)return left;
    else{
        return root;
    }

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
    cout<<lowestCommonAncestor(root, leftChild_left,rightChild)->data;
    return 0;
    //         2
    //        / \
    //       3   5
    //      / \
    //    35   4
}