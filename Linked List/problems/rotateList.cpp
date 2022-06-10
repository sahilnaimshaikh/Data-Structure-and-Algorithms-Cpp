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
     ListNode* rotateRight(ListNode* head, int k) {
           if(head == NULL || head->next == NULL || k==0)return head;
         int length = 1;
         ListNode * dummyhead = head;
         ListNode * dummyhead1 = head;
      while(dummyhead->next!=NULL){// finding the length of the linked list
          dummyhead = dummyhead->next;
          length++;
      }  
      dummyhead->next = head; // making the linked list circular
      dummyhead = head;
    

      if(length<=k) k = k%length; // if given k is larger than the length then we have to find the modulo
        if(k == 0) return head; //if the k has become 0 that means there is no change in linkedlist.
     
      for (int i = 0; i < length-k-1; i++)
      {
          dummyhead1 = dummyhead1->next;
      }
        ListNode * newhead = dummyhead1->next; 
        dummyhead1->next = NULL;
      
      

      return newhead;
      
      
      
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
    head = sol.rotateRight(head,3);
    sol.traverseLinkedList(head);
    
          
          
return 0;
}