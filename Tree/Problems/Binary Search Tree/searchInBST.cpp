


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

// TreeNode* searchBST(TreeNode * root, int val){
//         if(!root)return NULL;
//     if(root->val == val) return root;
//     else{
//         if(val<root->val){
//             if(searchBST(root->left, val))return searchBST(root->left, val);
//         }
//         else{
//             if(searchBST(root->right, val))return searchBST(root->right, val);
//         }
//     }
//     return NULL;
//     }
TreeNode* searchBST(TreeNode * root, int val){
      while(root && root->val !=val){
         root = val<root->val?root->left:root->right;
      }
      return root;
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
    cout<<searchBST(root, 17)->val;
    return 0;

//         22
//     13     45
//   9   17     
}