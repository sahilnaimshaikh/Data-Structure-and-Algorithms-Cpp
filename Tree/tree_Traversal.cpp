#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *treeNode = (struct node *)malloc(sizeof(struct node));
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main()
{

    struct node *root = createNode(2);
    struct node *leftChild = createNode(3);
    struct node *rightChild = createNode(5);
    struct node *leftChild_left = createNode(35);
    struct node *leftChild_right = createNode(4);

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftChild_left;
    leftChild->right = leftChild_right;

    inOrder(root);

    return 0;
}