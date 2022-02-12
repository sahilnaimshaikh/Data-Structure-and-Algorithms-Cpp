#include<iostream>
#include<stdlib.h>

using namespace std;

        struct node{
            int data;
            struct node* next;
        };    

        void traverseLinkedList(struct node * ptr){
             while(ptr != NULL){
                 cout<<ptr->data<<" ";
                ptr = ptr->next;
             }
             cout<<endl;
         }
         struct node* insertAtBeginning(struct node* head, int data){
             struct node* ptr = (struct node*)malloc(sizeof(struct node));
             ptr->data = data;
             ptr->next = head;
             head = ptr;
             return head;
         }
         struct node* insertAtIndex(struct node* head, int data, int index){
             struct node* ptr = (struct node*) malloc(sizeof(struct node));
             ptr->data = data;
             int i = 0;
             struct node* p = head;
             while(i!=index-1){
                 p= p->next;
                 i++;
             }
             ptr->next = p->next;
             p->next = ptr;
             return head;
         }
         struct node* insertAtEnd(struct node* head, int data){
             struct node* ptr = (struct node*) malloc(sizeof(struct node));
             ptr->data = data;
             struct node* p = head;
             while(p->next!=NULL){
                 p = p->next;
             }
             ptr->next = NULL;
             p->next = ptr;
             return head;
         }
         struct node* insertAfterNode(struct node* head, struct node * node, int data){
             struct node* ptr = (struct node*) malloc(sizeof(struct node));
             ptr->data = data;
             ptr->next = node->next;
             node->next = ptr;
             return head;
         }

int main(){
            
        struct node* head = (struct node *) malloc(sizeof(struct node));
        struct node* first = (struct node *) malloc(sizeof(struct node));
        struct node* second = (struct node *) malloc(sizeof(struct node));
        struct node* third = (struct node *) malloc(sizeof(struct node));
        
        head->data = 12;
        head->next = first;

        first->data = 1212;
        first->next = second;

        second->data = 412;
        second->next = third;

        third->data = 8712;
        third->next = NULL;
        traverseLinkedList(head);

        // Insertions in linked list
                // 1) at beginning
                    // head = insertAtBeginning(head, 9);
                    // traverseLinkedList(head);

                // 2) in between 
                    // int index = 3;
                    // head = insertAtIndex(head, 9, index);
                    // traverseLinkedList(head);

                // 2) at the end
                    // head = insertAtEnd(head, 9);
                    // traverseLinkedList(head);
                    
                // 3) after any given node 
                    // head = insertAfterNode(head, second, 89);
                    // traverseLinkedList(head);

return 0;
}