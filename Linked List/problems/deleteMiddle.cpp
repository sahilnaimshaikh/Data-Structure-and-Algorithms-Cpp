#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
      ListNode* deleteMiddle(ListNode* head) {
       ListNode * s=head;
       ListNode * f=head;
        while(1){
             if( f->next==NULL){
                return NULL;
            }
             if(f->next->next==NULL || f->next->next->next ==NULL){
                s->next = s->next->next;
                 return head;
             }
           
            s = s->next;
            f = f->next->next;
           
        }
       
    }
      void traverseLinkedList(struct ListNode * ptr){
             while(ptr != NULL){
                 cout<<ptr->val<<" ";
                ptr = ptr->next;
             }
             cout<<endl;
         }
      
};
          
int main(){
          
 ListNode * head = (ListNode *)malloc(sizeof(ListNode));
//  ListNode * first = (ListNode *)malloc(sizeof(ListNode));
//  ListNode * second = (ListNode *)malloc(sizeof(ListNode));
//  ListNode * third = (ListNode *)malloc(sizeof(ListNode));
//  ListNode * fourth = (ListNode *)malloc(sizeof(ListNode));

   head->val = 1; 
//    first->val = 2; 
//    second->val = 3; 
//    third->val = 4; 
//    fourth->val = 5; 

    head->next = NULL;
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = NULL;

    

    Solution sol;
    sol.traverseLinkedList(head);
  head =  sol.deleteMiddle(head);
    sol.traverseLinkedList(head);
   
          
return 0;
}