
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createNode(int data)
{
    struct TreeNode *treeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    treeNode->val = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
    while (1)
    {
        if (node1->val < root->val && node2->val < root->val)
        {
            root = root->left;
        }
        else if (node1->val > root->val && node2->val > root->val)
        {
            root = root->right;
        }
        else
            return root;
    }
}

int main()
{
    struct TreeNode *root = createNode(4);
    struct TreeNode *leftChild = createNode(2);
    struct TreeNode *rightChild = createNode(5);
    struct TreeNode *leftChild_left = createNode(1);
    struct TreeNode *leftChild_right = createNode(3);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
    cout << lowestCommonAncestor(root, leftChild_left, rightChild)->val;
    //         4
    //        / \
    //       2   5
    //      / \
    //     1   3
}