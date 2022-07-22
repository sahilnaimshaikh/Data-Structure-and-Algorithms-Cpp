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

vector<int> iterativePreorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL)return ans;
    stack<TreeNode*> st;
    st.push(root);
    while(st.empty()!=1){
        TreeNode* node = st.top();
        st.pop();
        if(node->right != NULL)st.push(node->right);
        if(node->left != NULL)st.push(node->left);
        ans.push_back(node->data);
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
    for(auto it : iterativePreorderTraversal(root))cout<<it<<" ";
    return 0;
}