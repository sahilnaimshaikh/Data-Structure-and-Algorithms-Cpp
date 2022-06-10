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
      ListNode* swapNodes(ListNode* head, int k) {
          if(head == NULL)return NULL;
          if(head->next == NULL) return head;
        ListNode *ptr = head;
        ListNode *ptr2 = head;
        int n = 0;
        while(ptr){
            n++;
            ptr=ptr->next;
        }
        ptr = head;
        n = n-k;
        while(n){
            ptr2 = ptr2->next;
            n--;
        }
        while(k>1){
            ptr = ptr->next;
            k--;
        }
        swap(ptr->val, ptr2->val);
        return head;
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
    head = sol.swapNodes(head,2);
    sol.traverseLinkedList(head);
        
    
          
          
return 0;
}