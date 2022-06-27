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
void traverse(TreeNode *root, vector<int> &inorder, vector<int> &preorder, vector<int> &postorder){
    if(root == NULL) return;
    preorder.push_back(root->data);
    traverse(root->left, inorder,preorder,postorder);
    inorder.push_back(root->data);
    traverse(root->right, inorder,preorder,postorder);
    postorder.push_back(root->data);
}
vector<vector<int>> inorderTraversal(TreeNode *root)
{   
    vector<vector<int>> ans;
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    traverse(root, inorder,preorder,postorder);
    ans.push_back(preorder);
    ans.push_back(inorder);
    ans.push_back(postorder);
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
   
       
    return 0;
}