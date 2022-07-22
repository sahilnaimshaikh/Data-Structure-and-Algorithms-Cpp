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
bool traverse1(TreeNode *root,int first, int second, vector<TreeNode*> & add){
    if(root == NULL) false;
    if(root->val == first)add.push_back(root);
    if(root->val == second)add.push_back(root);
    
    traverse1(root->left, first, second,add);
    traverse1(root->right, first, second,add);
}
   void recover(TreeNode* root) {
      
      vector<int> ans;
      traverse(root, ans);
      for(auto it : ans)cout<<it<<" ";
      int first = -1, second = -1;
      for (int i = 1; i < ans.size(); i++)
      {
        if(ans[i-1]>ans[i]){
            first = ans[i-1];
        break;
        }
      }
      for (int i = ans.size()-2 ; i >=0 ; i--)
      {
        if(ans[i+1] < ans[i]){
             second = ans[i+1];
            break;
        }
      }
      TreeNode* node1 = NULL;
      TreeNode* node2 = NULL;
      vector<TreeNode*> add;
      traverse1(root, first, second,add);  
       node1 = add[0];
       node2 = add[1];
       swap(node1->val, node2->val); 
      
      
        
    }

//         22
//     13     45
//   9   17    


int main()
{
     struct TreeNode *root = createNode(4);
    struct TreeNode *leftChild = createNode(5);
    struct TreeNode *rightChild = createNode(3);
    // struct TreeNode *leftChild_left = createNode(22);
    // struct TreeNode *leftChild_right = createNode(17);

    root->left = leftChild;
    root->right = rightChild;
    // leftChild->left = leftChild_left;
    // leftChild->right = leftChild_right;
    recover(root);
    return 0;

//         22
//     13     45
//   9   17     
}