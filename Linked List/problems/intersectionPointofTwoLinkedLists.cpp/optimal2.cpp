#include<bits/stdc++.h>
using namespace std;
class ListNode
{ 
  public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
     ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * a = headA;
        ListNode* b = headB;
        if(a==NULL || b==NULL)return NULL;
        
        while(a!=b){
           if(a==NULL)a=headB;
               else a=a->next;
            if(b==NULL)b=headA;
            else b= b->next;
        }
        return b;
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