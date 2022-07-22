
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

string serialize(TreeNode *root)
{

    string s = "";
    if (root == NULL)
        return s;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if(node == NULL){
            s.append("$,");
        }
        else{
        s.append(to_string(node->data) + ',');
        }
        if(node != NULL){
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode *deserialize(string data)
{
    if(data.size()== 0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode * root =  createNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode * node = q.front();
        q.pop();
        
        getline(s,str,',');
        if(str == "$")node->left = NULL;
        else{
            TreeNode * nodeleft =  createNode(stoi(str));
            node->left = nodeleft;
            q.push(nodeleft);
        }
        getline(s,str,',');
        if(str == "$")node->right = NULL;
        else{
            TreeNode * noderight =  createNode(stoi(str));
            node->right = noderight;
            q.push(noderight);
        }

    }
    return root;
}

void traverse(TreeNode *root, vector<int> &ans){
    if(root == NULL) return;
    ans.push_back(root->data);
    traverse(root->left, ans);
    traverse(root->right, ans);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    traverse(root, ans);
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
   string s = serialize(root);
   
   for(auto it : preorderTraversal(deserialize(s)))cout<<it<<" ";
    return 0;
    //         2
    //        / \
    //       3   5
    //      / \
    //    35   4
}