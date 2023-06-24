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

          struct node* deleteAtStart(struct node* head){
              struct node* ptr = head;
              head = head->next;
              free(ptr);
              return head;  
          }

          struct node* deleteAtIndex(struct node* head, int index){
            //   Method 1
                //   struct node* ptr = head;
                //   struct node* q = head->next;
                //   for(int i = 0; i<index-1; i++){
                //       ptr = ptr->next;
                //       q = q->next;
                //   }
                //   ptr->next = q->next;
                //   free(q);
                //   return head;
            // Mthod 2
                  struct node* ptr = head;
                   int i = 0;
                   while(i<index-1){
                       ptr = ptr->next;
                       i++;
                   }      
                   struct node* q = ptr->next;
                   ptr->next = q->next;
                   free(q);      
                  return head;
          }
          struct node* deleteAtTheEnd(struct node* head){
              struct node* ptr = head;
              struct node* q = head->next;
              while(q->next!=NULL){
                  ptr = ptr->next;
                  q = q->next;
              }
              ptr->next = q->next;
              free(q);
              return head;
          }
          struct node* deleteAfterNode(struct node* head, struct node* element){
              struct node* ptr = element;
              struct node* q = element->next;
              ptr->next = q->next;
              free(q);
              return head;
          }
          struct node* deleteNode(struct node* element){
            element->data = element->next->data;
            element->next = element->next->next;
          }
        
int main(){
            
        struct node* head = (struct node *) malloc(sizeof(struct node));
        struct node* first = (struct node *) malloc(sizeof(struct node));
        struct node* second = (struct node *) malloc(sizeof(struct node));
        struct node* third = (struct node *) malloc(sizeof(struct node));
        struct node* fourth = (struct node *) malloc(sizeof(struct node));
        
        head->data = 12;
        head->next = first;

        first->data = 1212;
        first->next = second;

        second->data = 412;
        second->next = third;

        third->data = 8712;
        third->next = fourth;

        fourth->data = 1334;
        fourth->next = NULL;
        traverseLinkedList(head);
        
        // Deleting the node in the linked list. (Uncomment the below cases for output)

                // 1) Deletion at the beginning
                        //  head = deleteAtStart(head);
                        //  traverseLinkedList(head);
                // 2) Delete the node in the middle
                        // head = deleteAtIndex(head, 3);
                        // traverseLinkedList(head); 
                // 3) Delete the node at the end
                        // head = deleteAtTheEnd(head);
                        // traverseLinkedList(head); 
                    
                // 4) Delete the node after any given node
                        // head = deleteAfterNode(head, first);
                        // traverseLinkedList(head); 
                   
return 0;
}
