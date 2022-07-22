// There are 3 methods for constructing a BST from Preorder
// 1) Iterate over each element of preorder and insert into a BST.
// 2) since we know that Inorder of BST is always in ascending order we can sort the preorder and get it, after  having Inorder and Preorder we can construct a binary tree which eventually will be BST.
// 3) using range method

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

 TreeNode* traverse(vector<int>& preorder, int start, int end){
        
        if(start>end){
            
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[start]);
        if(start == end){
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        int i;
        for( i = start+1; i<= end; i++){
            if(preorder[i]>root->val)break;
        }
        root->left = traverse(preorder, start+1, i-1);
        root->right = traverse(preorder,i, end);
        
        return root;
    }
    TreeNode* bstFromPreorder1(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        return traverse(preorder, 0, preorder.size()-1);
        
    }


    TreeNode* build(vector<int>& A, int i, int ub){
        if(i == A.size() || A[i] > ub) return NULL;
        TreeNode* root = new TreeNode(A[i]);
        i++;
        root->left = build(A, i, root->val);
        root->right = build(A, i, ub);
        return root;
    }
    TreeNode* bstFromPreorder2(vector<int> & A){
        int i = 0;
        int ub = INT_MAX;
        build(A, i, ub);
    }

int main()
{



}