


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
// Note : Inorder Traversal of BST is always in ascending order
// 
// Brute force|||
// void traverse(TreeNode *root, vector<int> &ans){
//     if(root == NULL) return;
//     traverse(root->left, ans);
//     ans.push_back(root->val);
//     traverse(root->right, ans);
// }
//    bool isValidBST(TreeNode* root) {
      
//       vector<int> ans;
//       traverse(root, ans);
//        for (int i = 1; i < ans.size(); i++)
//        {
//          if(ans[i-1] >= ans[i]) return false;
//        }
//         return true;
//     }

//         22
//     13     45
//   9   17    

// optimal approach 
bool isValidBST(TreeNode* root, long min, long max){
    if(root==NULL) return true;
    if(root->val <= min || root->val >= max) return false;
    bool leftSubTree = isValidBST(root->left, min, root->val);
    bool rightSubTree = isValidBST(root->right, root->val, max);
    return leftSubTree and rightSubTree;
}
bool isValidBST(TreeNode * root){
    long min = LONG_MIN;
    long max = LONG_MAX;
    return isValidBST(root, min, max);
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
    cout<<isValidBST(root);
    return 0;

//         22
//     13     45
//   9   17     
}