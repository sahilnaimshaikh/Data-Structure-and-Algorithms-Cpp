#include<iostream>
using namespace std;
            
          struct linked1{// declarring a user define dataType..we can relate a structure in c/cpp as an object in javascript. 
             int data;
             struct linked1 * nextAddress;
         };

         void traverseLinkedList(struct linked1 * ptr){
             struct linked1* p = ptr;
            do{
                cout<<p->data<<" ";
                p = p->nextAddress;
            }while(p!=ptr);
         }

int main(){
            
         struct linked1 * head; //declaring an object of a userdefined datatype
           struct linked1 * first;
           struct linked1 * second;

            // malloc(size in bytes) returns an address(void pointer) to the allocated memory 
           head = (struct linked1 *)malloc(sizeof(struct linked1)); 
           first = (struct linked1 *)malloc(sizeof(struct linked1)); 
           second = (struct linked1 *)malloc(sizeof(struct linked1)); 
        
           head->data = 34;
           head->nextAddress = first;

           first->data = 4;
           first->nextAddress = second;
           
           second->data = 9;
           second->nextAddress = head;



           traverseLinkedList(head); 
            
return 0;
}