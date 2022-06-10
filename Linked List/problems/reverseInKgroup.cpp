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
       ListNode* reverseKGroup(ListNode* head, int k) {

           if(head == NULL || k == 1)return head;
           ListNode * dummy = (ListNode*)malloc(sizeof(ListNode));
           dummy->next = head;
           ListNode *pre = dummy, *cur = dummy, *next = dummy;
           int count = 0;
           while(cur->next != NULL){
               cur = cur->next;
               count++;
           } 
           while(count>=k){
               cur = pre->next;
               next = cur->next;
               for (int i = 0; i < k-1; i++)
               {
                   cur->next = next->next;
                   next->next = pre->next;
                   pre->next = next;
                   next = cur->next;
               }
               pre = cur;
               count -= k;
               
           }
            return dummy->next;
        
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
 ListNode * first = (ListNode *)malloc(sizeof(ListNode));
 ListNode * second = (ListNode *)malloc(sizeof(ListNode));
 ListNode * third = (ListNode *)malloc(sizeof(ListNode));
 ListNode * fourth = (ListNode *)malloc(sizeof(ListNode));

   head->val = 1; 
   first->val = 2; 
   second->val = 3; 
   third->val = 4; 
   fourth->val = 5; 

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    

    Solution sol;
    sol.traverseLinkedList(head);
    head = sol.reverseKGroup(head,3);
    sol.traverseLinkedList(head);
        
    
          
          
return 0;
}