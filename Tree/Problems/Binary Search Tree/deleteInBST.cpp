


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

    TreeNode* findRight(TreeNode* root){
        while(root->right!=NULL){
            root = root->right;
        }
        return root;
    }
    TreeNode* join(TreeNode* root){
        if(!root->left)return root->right;
        else if(!root->right) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* right = findRight(root->left);
        right->right = rightChild;

        return root->left;

    }
 TreeNode * deleteNode(TreeNode * root, int val){
  
        if(!root) return NULL;
        if(root->val == val) return join(root);
        TreeNode* node = root;
        while(root){
            if(val < root->val){
                
                if(root->left != NULL && root->left->val == val){
                    root->left = join(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                    if(root->right != NULL && root->right->val == val){
                    root->right = join(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }

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
    cout<<deleteNode(root, 17);
    return 0;

//         22
//     13     45
//   9   17     
}