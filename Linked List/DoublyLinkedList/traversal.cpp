#include<iostream>
using namespace std;

        struct node{
            struct node* previous;
            int data;
            struct node* next;
        };    

        void traverse(struct node* head){
            struct node* ptr = head;

            cout<<"Forward Traversal"<<endl;
            do{
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }while(ptr->next!=NULL);
             cout<<ptr->data<<" ";

             
            cout<<"\n Backward Traversal"<<endl;
            do{
                
                cout<<ptr->data<<" ";
                ptr = ptr->previous;
            }while(ptr->previous!=NULL);
            cout<<ptr->data<<" ";

        }
            
int main(){
            
        struct node* head = (struct node* )malloc(sizeof(struct node));
        struct node* second = (struct node* )malloc(sizeof(struct node));
        struct node* third = (struct node* )malloc(sizeof(struct node));
        struct node* fourth = (struct node* )malloc(sizeof(struct node));
        struct node* fifth ;
        head->data = 23;
        head->previous = NULL;
        head->next = second;

        second->data = 54;
        second->previous = head;
        second->next = third;

        third->data = 87;
        third->previous = second;
        third->next = fourth;

        fourth->data = 13;
        fourth->previous = third;
        fourth->next = NULL;

        fifth->data = 34;
        cout<<fifth->data;
        // traverse(head);

return 0;
}
