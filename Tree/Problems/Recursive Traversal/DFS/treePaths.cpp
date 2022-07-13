


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
 void traverse(TreeNode *root, vector<vector<int>> &ans, vector<int> &s){
      
        s.push_back(root->data);
        
        if(!root->left && !root->right){
            ans.push_back(s);
            s.pop_back();
            return;
        }
    
        traverse(root->left, ans,  s);
        traverse(root->right, ans,  s);
        s.pop_back();
    }
    vector<vector<int>> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> s;
        if(root == NULL)return ans;
        traverse(root, ans, s);
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
    for(auto it : binaryTreePaths(root)){
        for(auto i : it){
            cout<<i<<" ";

        }
        cout<<endl;
    }
    return 0;
    //         2
    //        / \
    //       3   5
    //      / \
    //    35   4
}