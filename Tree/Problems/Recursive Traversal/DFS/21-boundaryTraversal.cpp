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
void traverse(TreeNode *root, vector<int> &inorder, vector<int> &preorder, vector<int> &postorder)
{
    if (root == NULL)
        return;
    preorder.push_back(root->data);
    traverse(root->left, inorder, preorder, postorder);
    inorder.push_back(root->data);
    traverse(root->right, inorder, preorder, postorder);
    postorder.push_back(root->data);
}
bool isLeaf(TreeNode *root)
{
    if (root && !root->left && !root->right)
        return true;
    return false;
}
void traverseLeftBoundary(TreeNode *root, vector<int> &result)
{

    TreeNode *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            result.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
void traverseLeaf(TreeNode *root, vector<int> &result)
{
    if(root && !root->left && !root->right){
        result.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, result);
    traverseLeaf(root->right, result);
}
void traverseRightBoundary(TreeNode *root, vector<int> &result)
{   
    vector<int> temp;

    TreeNode *cur = root->right;
    while (cur)
    {
        if (!isLeaf(cur))
            temp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = temp.size()-1; i >=0 ; i--)
    {
        result.push_back(temp[i]);
    }
    
}
vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;
    if (!isLeaf(root))
        result.push_back(root->data);
    traverseLeftBoundary(root, result);
    traverseLeaf(root, result);
    traverseRightBoundary(root, result);
    return result;
}

int main()
{
    struct TreeNode *root = createNode(2);
    struct TreeNode *leftChild = createNode(3);
    struct TreeNode *rightChild = createNode(5);
    struct TreeNode *leftChild_left = createNode(35);
    struct TreeNode *leftChild_right = createNode(4);
    struct TreeNode *rightChild_left = createNode(6);
    struct TreeNode *rightChild_right = createNode(8);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
    rightChild->left = rightChild_left;
    rightChild->right = rightChild_right;
    // cout<<isLeaf(NULL);
    for(auto it: boundaryTraversal(root))cout<<it<<" ";
    return 0;
}