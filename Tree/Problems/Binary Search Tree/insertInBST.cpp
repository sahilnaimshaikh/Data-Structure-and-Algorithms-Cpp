


#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
struct TreeNode *createNode(int data)
{
    struct TreeNode *treeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    treeNode->val = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}

 TreeNode * insertIntoBST(TreeNode * root, int val){
    
    TreeNode* node = root;
     while(root){
        
        if(val < root->val){
            if(root->left) root = root->left;
            else break;
        }
        else{
            if(root->right) root = root->right;
            else break;
        }
     }
     if(root->val < val)root->right = new TreeNode(val);
     else{
        root->left = new TreeNode(val);
     }


    return node;
    }

//         22
//     13     45
//   9   17    


int main()
{
     struct TreeNode *root = createNode(22);
    struct TreeNode *leftChild = createNode(13);
    struct TreeNode *rightChild = createNode(45);
    struct TreeNode *leftChild_left = createNode(9);
    struct TreeNode *leftChild_right = createNode(17);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
    cout<<insertIntoBST(root, 18);
    return 0;

//         22
//     13     45
//   9   17     
}