
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
bool findTarget(TreeNode* root, int target, unordered_map<int, int>& map, bool& flag){
    if(!root) return false;
    if(map.find(target-root->val)!=map.end()){
        flag = true;
        return true;
    }
    map[root->val] = root->val;
    if(findTarget(root->left, target, map,flag)) return true;
    if(findTarget(root->right, target, map,flag)) return true;
    return false;
}
bool findTarget(TreeNode* root, int target){
    unordered_map<int, int> map;
    bool flag = false;
    findTarget(root, target, map, flag);
  return  flag;
}


int main()
{
    struct TreeNode *root = createNode(4);
    struct TreeNode *leftChild = createNode(2);
    struct TreeNode *rightChild = createNode(5);
    struct TreeNode *leftChild_left = createNode(1);
    struct TreeNode *leftChild_right = createNode(3);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
    cout << findTarget(root, 9);
    //         4
    //        / \
    //       2   5
    //      / \
    //     1   3
}