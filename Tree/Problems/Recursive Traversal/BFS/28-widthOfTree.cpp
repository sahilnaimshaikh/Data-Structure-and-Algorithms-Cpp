

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

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    int maxWidth = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int first, last;
        int min = q.front().second;
        for (int i = 0; i < size; i++)
        {   
            int currVal = q.front().second - min;
            TreeNode *node = q.front().first;
            q.pop();
            if (i == 0)
                first = currVal;
            if (i == size - 1)
                last = currVal;
            if (node->left)
                q.push({node->left, currVal * 2 + 1});
            if (node->right)
                q.push({node->right, currVal * 2 + 2});
        }
        maxWidth = max(maxWidth, last - first + 1);
    }
    return maxWidth;
}

int main()
{
    struct TreeNode *root = createNode(2);
    struct TreeNode *leftChild = createNode(3);
    struct TreeNode *rightChild = createNode(5);
    struct TreeNode *leftChild_left = createNode(35);
    struct TreeNode *leftChild_right = createNode(4);
    struct TreeNode *rightChild_right = createNode(9);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
    rightChild->right = rightChild_right;
    cout << widthOfBinaryTree(root);
    return 0;
    //         2
    //        / \
    //       3   5
    //      / \   \  
    //    35   4   9
}