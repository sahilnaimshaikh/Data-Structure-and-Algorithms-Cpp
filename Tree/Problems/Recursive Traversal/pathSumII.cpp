


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
    void traverse(TreeNode* root, int targetSum, vector<int> &ds, vector<vector<int>> &ans){
        if(!root){return;}
        
        ds.push_back(root->data);
        targetSum-=root->data;
        if(targetSum == 0 && !root->left && !root->right){
            ans.push_back(ds);
            ds.pop_back();
            return;
        }
        traverse(root->left, targetSum, ds, ans);
        traverse(root->right, targetSum, ds, ans);
        ds.pop_back();
    }
   vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans;
       vector<int> ds;
       traverse(root, targetSum, ds, ans);
       return ans;

    }
int main()
{
     struct TreeNode *root = createNode(2);
    struct TreeNode *leftChild = createNode(3);
    struct TreeNode *rightChild = createNode(5);
    struct TreeNode *leftChild_left = createNode(9);
    struct TreeNode *leftChild_right = createNode(4);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
    for(auto it : pathSum(root, 9)){
        for(auto i : it)cout<<i<<" ";
        cout<<endl;
    }
    return 0;

//         2
//     3       5
// 9    4     
}