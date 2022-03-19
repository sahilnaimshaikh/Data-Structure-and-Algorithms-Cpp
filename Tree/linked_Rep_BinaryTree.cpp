#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};       
struct node* createNode(int data){
    struct node * treeNode = (struct node *)malloc(sizeof(struct node));
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
} 


int main(){

     struct node* root = createNode(2);
     struct node* leftChild = createNode(3);
     struct node* rightChild = createNode(5);

     root->left = leftChild;      
     root->right = rightChild; 

    cout<<root->data;
    cout<<root->left->data; 
    cout<<root->left->data; 
    
            
return 0;
}