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
void traverse(TreeNode *root, vector<int> &ans){
    if(root == NULL) { 
        ans.push_back(INT_MAX);
        return;}
    ans.push_back(root->data);
    traverse(root->left, ans);
    traverse(root->right, ans);
}
bool isSameTree(TreeNode* p, TreeNode* q) 
{
    vector<int> ans1;
    vector<int> ans2;
    traverse(p, ans1);
    traverse(q, ans2);
    if(ans1.size() == ans2.size()){
        for (int i = 0; i < ans1.size(); i++)
        {
            if(ans1[i]!=ans2[i]) return false;
        }
        return true;
    }
    else return false;
}

int main()
{
     struct TreeNode *root = createNode(2);
     struct TreeNode *root2 = createNode(2);
    struct TreeNode *leftChild = createNode(3);
    struct TreeNode *rightChild = createNode(5);
    struct TreeNode *leftChild_left = createNode(35);
    struct TreeNode *leftChild_right = createNode(4);

    root->left = leftChild;
    root2->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
    cout<<isSameTree(root, root2);
    return 0;
}