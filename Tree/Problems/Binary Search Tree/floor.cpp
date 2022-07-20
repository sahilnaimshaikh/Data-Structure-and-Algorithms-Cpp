


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


int floor(TreeNode * root, int val){
     int floor = INT_MIN;
     while(root){
        if(root->val == val)return val;
        // if(root->val < val)
        if(val < root->val){
            
            root = root->left;
        }
        else{
             floor = max(floor, root->val);
            root = root->right;
        }
     }
    return floor;
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
    cout<<floor(root, 18);
    return 0;

//         22
//     13     45
//   9   17     
}