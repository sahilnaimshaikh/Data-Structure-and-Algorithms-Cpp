


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
vector<vector<int>> levelorderTraversal(TreeNode *root)
{
   vector<vector<int>> ans;
   if(root == NULL) return ans;
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
   return ans;
}
    //         2
    //        / \
    //       3   5
    //      / \
    //    35   4
void childrenSumProperty(TreeNode *root){
    if(!root || (root->left == NULL && root->right == NULL))return;// if the root is NULL or if it is a leaf then i will return


    if(root->left->data + root->right->data < root->data){ // if the submission of data of left and right node is less than the data of root node then this will happen
        root->left->data = root->data;
        root->right->data = root->data;
    }

    childrenSumProperty(root->left);
    childrenSumProperty(root->right);

    // while returning i will always assign the data of root as addition of data of left and right node
    root->data = root->left->data + root->right->data;
     
     return;

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
        childrenSumProperty(root);
        //level order traversal is used to print the output...
      for(auto it : levelorderTraversal(root)){
        for(auto i: it) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
    //         2
    //        / \
    //       3   5
    //      / \
    //    35   4
}