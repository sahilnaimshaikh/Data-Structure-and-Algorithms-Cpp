#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
   ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
     if(headA == NULL || headB== NULL ) return NULL;
     ListNode * d1 = headA;
     ListNode * d2 = headB;
     int s1 = 0, s2 = 0;
     while(d1!=NULL || d2!=NULL){
         if(d1!=NULL){
             d1= d1->next;
             s1++;}
         if(d2!=NULL){
             s2++;
             d2= d2->next;
         }
         
         
     }
     
     d1 = headA;
     d2 = headB;
     if(s1!=s2){
     int diff = s1<s2?s2-s1:s1-s2;
    
     if(s1>s2){
         
         for (int  i = 0; i < diff; i++)
         {
             d1 = d1->next;
         }
     }
     else{
         
         for (int  i = 0; i < diff; i++)
         {
             d2 = d2->next;
         }
     
     }}
     while (d1!=NULL|| d2!=NULL)
     {  
         if(d1==d2) break;
        d1 = d1->next;
        d2 = d2->next;
     }
     return d1;
     
    }      

};
          
int main(){
          
     ListNode *head = (ListNode *)malloc(sizeof(ListNode));
  ListNode *first = (ListNode *)malloc(sizeof(ListNode));
  ListNode *second = (ListNode *)malloc(sizeof(ListNode));
  ListNode *third = (ListNode *)malloc(sizeof(ListNode));
  ListNode *fourth = (ListNode *)malloc(sizeof(ListNode));

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

   ListNode *head1 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *first1 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *second1 = (ListNode *)malloc(sizeof(ListNode));
 

  head1->val = 3;
  first1->val = 7;
  second1->val = 3;
 

  head1->next = first1;
  first1->next = second1;
  second1->next = second;

Solution sol;
cout<<sol.getIntersectionNode(head,head1)->val;
     
          
          
return 0;
}