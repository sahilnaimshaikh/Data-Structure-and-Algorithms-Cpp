


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
bool traverse(TreeNode *root, int& k, int& ans){
    if(root == NULL) return false;
    if(traverse(root->left, k, ans)) return true;
    k--;
    if(k==0){
        ans =  root->val;
        return true;
    }
    if(traverse(root->right, k, ans)) return true;
    return false;
}
   int kthSmallest(TreeNode* root, int k) {
      
      int ans;
      traverse(root, k, ans);
      return ans;  
    }

//         22
//     13     45
//   9   17    


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
    cout<<kthSmallest(root, 2);
    return 0;

//         22
//     13     45
//   9   17     
}