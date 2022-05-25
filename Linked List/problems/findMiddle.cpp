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
     ListNode * findMiddle(ListNode * head) {
       ListNode * s=head;
       ListNode * f=head;
        while(f!=NULL || f->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        return s;
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
    
   cout<<sol.findMiddle(head)->val;
   
          
return 0;
}