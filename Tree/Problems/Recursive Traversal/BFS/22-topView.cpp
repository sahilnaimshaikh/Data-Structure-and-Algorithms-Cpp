


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

vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode*, int>> q;
    map<int, int> mpp;
    q.push({root, 0});

    while(!q.empty()){
        TreeNode* node = q.front().first;
        int colNo = q.front().second;
        q.pop();
        if(mpp.find(colNo) == mpp.end()) mpp[colNo] = node->data;
        if(node->left) q.push({node->left, colNo-1});
        if(node->right) q.push({node->right, colNo+1});
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
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
    for(auto it : topView(root))cout<<it<<" ";
    return 0;
}