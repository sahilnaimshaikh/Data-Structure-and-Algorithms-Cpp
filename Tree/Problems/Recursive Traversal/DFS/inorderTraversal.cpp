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
void traverse(TreeNode *root, vector<int> &ans, int & count){
    if(root == NULL) return;
    count++;
    traverse(root->left, ans,count);
    ans.push_back(root->data);
    traverse(root->right, ans, count);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    int count = 0;
    traverse(root, ans, count);
    return ans;
}

int main()
{
    
     struct TreeNode *root = createNode(22);
    struct TreeNode *leftChild = createNode(13);
    struct TreeNode *rightChild = createNode(45);
    struct TreeNode *leftChild_left = createNode(9);
    struct TreeNode *leftChild_right = createNode(17);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
   
    for(auto it : inorderTraversal(root))cout<<it<<" ";
    return 0;
}