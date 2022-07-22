

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

void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parents)
{
    if (!root)
        return;
    parents[root->left] = root;
    parents[root->right] = root;
    markParent(root->left, parents);
    markParent(root->right, parents);
}
int burnTree(TreeNode *root, TreeNode *target)
{
    unordered_map<TreeNode *, TreeNode *> parents;
    unordered_map<TreeNode *, bool> visited;
    markParent(root, parents);
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int count = -1;// count is starting from -1 bcoz the leaf nodes will not burn any nodes but still the count will be incremented that is why just to balance that we have taken it as -1;
    while (!q.empty())
    {
                int size = q.size();
        for (int i = 0; i < size; i++)
        {

            TreeNode *node = q.front();
            q.pop();
            if (node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }

            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }

            if (parents[node] && !visited[parents[node]])
            {
                q.push(parents[node]);
                visited[parents[node]] = true;
            }
        }
        count++;
    }

    return count;
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
    cout << burnTree(root, rightChild);
    return 0;
    //         2
    //        / \
    //       3   5
    //      / \
    //    35   4
}