


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
 bool traverse(TreeNode* root,int n, vector<int> &ans){
    if(!root) return false;
    ans.push_back(root->data);
    if(root->data == n){
        return true;
    }
    if(traverse(root->left, n, ans))return true;
    if(traverse(root->right, n, ans))return true;
    ans.pop_back();
    return false;
}
int lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2){
    vector<int> ans1;
    vector<int> ans2;
    if(!root) return -1;
    traverse(root,node1->data, ans1);
    traverse(root,node2->data, ans2);
    int n = 0 , m = 0, i = -1;
    while(n < ans1.size() && m < ans2.size()){
        if(ans1[n] == ans2[m]) n++, m++, i++;
        else break;
    }
   return ans1[i];
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
    cout<<lowestCommonAncestor(root, leftChild_left,rightChild);
    return 0;
    //         2
    //        / \
    //       3   5
    //      / \
    //    35   4
}