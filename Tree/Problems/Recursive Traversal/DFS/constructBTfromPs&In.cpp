
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


    TreeNode* build(vector<int>& posorder,int posStart, int posEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> inMap){

        if(posStart > posEnd || inStart > inEnd) return NULL;

        TreeNode * root = createNode(posorder[posStart]);

        int inRoot = inMap[root->data];
        int numsleft = inRoot - inStart;

        root->left = build(posorder, posStart, posStart+numsleft, inorder, inStart, inRoot-1, inMap);
        root->right = build(posorder, posStart+numsleft, posEnd-1, inorder, inRoot+1, inEnd, inMap);
        return root;


    }





 TreeNode* buildTree(vector<int>& posorder, vector<int>& inorder) {

        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }
        int posStart = 0;
        int inStart = 0;
        int posEnd = posorder.size()-1;
        int inEnd = inorder.size()-1;
        TreeNode * root = build(posorder, posStart, posEnd, inorder, inStart, inEnd, inMap);
         return root;
                
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
    
    return 0;
    //         2
    //        / \
    //       3   5
    //      / \
    //    35   4
}