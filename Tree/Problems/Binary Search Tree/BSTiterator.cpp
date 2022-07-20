
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
class BSTIterator {
    private: stack<TreeNode*> st;
            void pushAll(TreeNode* root){
                while(root){
                    st.push(root);
                    root  = root->left;
                }
            }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};




int main()
{
    struct TreeNode *root = createNode(4);
    struct TreeNode *leftChild = createNode(2);
    struct TreeNode *rightChild = createNode(5);
    struct TreeNode *leftChild_left = createNode(1);
    struct TreeNode *leftChild_right = createNode(3);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;
    BSTIterator obj = BSTIterator(root);
    cout<<obj.next();
    //         4
    //        / \
    //       2   5
    //      / \
    //     1   3
}