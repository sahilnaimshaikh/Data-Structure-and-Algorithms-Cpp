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
    bool hasCycle(ListNode *head) {
       if(head==NULL || head->next == NULL) return false;

       ListNode * s = head; 
       ListNode * f = head; 

        while (f->next != NULL && f->next->next!=NULL)
        {
            f = f->next->next;
            s = s->next;
            if(f == s) return true;
        }
        return false;
        

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
    third->val = 2;
    fourth->val = 2;

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;         
    
       Solution sol;
       cout<<sol.hasCycle(head);   
          
return 0;
}