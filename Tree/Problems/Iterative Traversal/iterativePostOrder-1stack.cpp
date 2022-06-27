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

vector<int> iterativePostOrderTraversal(TreeNode *root)
{
   stack<TreeNode*> st;
   vector<int> ans;
   TreeNode* current = root;
   st.push(current);
   while (current!=NULL || !st.empty())
   {    
        if(current != NULL){
            st.push(current);
            current = current->left;
        }
        else{
            TreeNode* temp = st.top()->right;
             if(temp == NULL){
                temp = st.top();
                ans.push_back(temp->data);
                st.pop();
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    ans.push_back(temp->data);
                    st.pop();
                }
             }
             else{
                current = temp;
             }
        }
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
    for(auto it : iterativePostOrderTraversal(root))cout<<it<<" ";
    return 0;
}