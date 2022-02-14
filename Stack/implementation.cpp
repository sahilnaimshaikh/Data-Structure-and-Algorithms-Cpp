#include<iostream>
using namespace std;

        struct node{
            int data;
            struct node* next;
        };  
        int isEmpty(struct node* top){
            if(top == NULL){
                return 1;
            }
            else{
                return 0;
            }
        }
        int isFull(struct node* top){
            struct node* p = (struct node*)malloc(sizeof(struct node));
            if (p == NULL)
            {
                return 1;
            }
            else{
                return 0;
            }
            
        }
        void traverse(struct node* top){
           if(!isEmpty(top)){
            struct node* p = top;
            while(p!=NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<endl;
           }
           else{
               cout<<"Can't Traverse stack is empty.";
           }
        }

        struct node* push(struct node* top, int element){
            if(!isFull(top)){
            struct node* q = (struct node*)malloc(sizeof(struct node));
            q->data = element;
            q->next = top;
            top = q;
            return top;
            }
            else{
                cout<<"Stack overflown";
            }
        }
       struct node* pop(struct node* top){
           if(!isEmpty(top)){
           struct node* q = top;
           top = top->next;
           free(q);
            return top;
           }
           else{
               cout<<"Stack is Empty, Can't Pop";
           }
        }
        
            
int main(){
            
        struct node* top = NULL;
        // cout<<isEmpty(top)<<endl;   
        // cout<<isFull(top)<<endl;   
        top = push(top, 287);
        top = push(top, 2);
        top = push(top, 54);
        top = push(top, 65);
        
        top = pop(top);
        top = pop(top);
        top = pop(top);
        // top = pop(top);

        traverse(top);

return 0;
}