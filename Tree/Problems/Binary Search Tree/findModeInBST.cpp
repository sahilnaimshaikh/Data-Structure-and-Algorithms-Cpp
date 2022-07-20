


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
void Traverse(TreeNode *root, unordered_map<int, int>& traverse){
    if(root == NULL) return;
    Traverse(root->left, traverse);
    if(traverse[root->val]>=1)traverse[root->val]++;
    else traverse[root->val] = 1;
    Traverse(root->right, traverse);
}
   vector<int>  findMode(TreeNode* root) {
      
      vector<int> ans;
      unordered_map<int, int> traverse;  
      Traverse(root, traverse);
      int maxi = INT_MIN;
      for (auto it : traverse)
      {
        maxi = max(it.second, maxi);
      }
        for (auto it : traverse)
        {
            if(it.second == maxi) ans.push_back(it.first);
        }
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
    for(auto it : findMode(root))cout<<it<<" ";
    return 0;

//         22
//     13     45
//   9   17     
}