


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
void traverse(TreeNode *root, vector<int> &ans){
    if(root == NULL) return;
    traverse(root->left, ans);
    ans.push_back(root->val);
    traverse(root->right, ans);
}
   int maxAncestorDiff(TreeNode* root) {
      
      vector<int> ans;
      traverse(root, ans);
      return max(abs(root->val - ans[0]), abs(root->val-ans[ans.size()-1])); 
        
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
    cout<<maxAncestorDiff(root);
    return 0;

//         22
//     13     45
//   9   17     
}