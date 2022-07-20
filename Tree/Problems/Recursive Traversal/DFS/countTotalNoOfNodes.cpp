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

int leftHeight(TreeNode *root)
{
    int h = 0;
    while (root)
    {
        h++;
        root = root->left;
    }
    return h;
}
int rightHeight(TreeNode *root)
{
    int h = 0;
    while (root)
    {
        h++;
        root = root->right;
    }
    return h;
}

int count(TreeNode *root)
{

    if (!root)
        return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh)
    {
        return pow(2, rh) - 1;
    }
    int leftSideNodes = count(root->left);
    int rightSideNodes = count(root->right);
    return 1 + leftSideNodes + rightSideNodes;
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
    cout << count(root);
    return 0;
}