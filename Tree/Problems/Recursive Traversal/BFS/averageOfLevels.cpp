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

  
    vector<double> averageOfLevels(TreeNode *root)
{   
    vector<double> ansArr;
   vector<vector<int>> ans;
   if(root == NULL) return ansArr;
   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty()){
    vector<int> level;
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        TreeNode* node = q.front();
        q.pop();
        if(node->left != NULL)q.push(node->left);
        if(node->right != NULL)q.push(node->right);
        level.push_back(node->data);
    }
    ans.push_back(level);
   }
        
   for(int i = 0 ; i< ans.size(); i++){
       double count = 0.0;
       for(int j = 0; j < ans[i].size() ; j++){
           count+=ans[i][j];
           cout<<count;
       }
       count = (double)count/(double)ans[i].size();
       ansArr.push_back(count);
   }
   return ansArr;
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
    for(auto it : averageOfLevels(root))cout<<it<<" ";
    return 0;
}