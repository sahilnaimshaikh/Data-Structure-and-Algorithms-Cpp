
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
             bool reverse = true;

            void pushAll(TreeNode* root){
                while(root){
                    st.push(root);
                    if(!reverse){                  
                    root  = root->left;
                    }
                    else{                      
                        root = root->right;
                    }
                }
            }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

bool findTarget(TreeNode* root, int target){
     BSTIterator left = BSTIterator(root, false);
    BSTIterator right = BSTIterator(root, true);
    // cout<<left.next();
    // cout<<right.next();
    int l = left.next();
    int r = right.next();
    while(l < r){
    if(l + r == target)return true;
    else if(l + r > target) r = right.next();
    else l = left.next();
    }
    return false;

}



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
   
    cout << findTarget(root, 9);





    //         4
    //        / \
    //       2   5
    //      / \
    //     1   3
}