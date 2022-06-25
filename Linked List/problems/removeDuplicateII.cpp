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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head->next == NULL || head == NULL) return NULL;
        ListNode * dummyHead = (ListNode*)malloc(sizeof(ListNode));
        dummyHead->next = head;
        ListNode * dh = dummyHead;

       ListNode * d = head;
        ListNode * d1 = head->next; // dh 1 1 2 3 3 4 5 5 6
        while(d->next!=NULL){
        if(d->val == d1->val){   
        while(d1->val==d->val){
            d1 = d1->next;
            if(d1==NULL){
                dh->next = d1;
                return dummyHead->next;
            }
        }
        dh->next = d1;
        d = d1;
        d1 = d->next;
        }
        else{
            dh = d;
            d1 = d1->next;
            d = d->next;
        }
        }
        return dummyHead->next;
    }

    void traverseLinkedList(struct ListNode *ptr)
  {
    while (ptr != NULL)
    {
      cout << ptr->val << " ";
      ptr = ptr->next;
    }
    cout << endl;
  }    
};
          
int main(){

  ListNode *head = (ListNode *)malloc(sizeof(ListNode));
  ListNode *first = (ListNode *)malloc(sizeof(ListNode));
  ListNode *second = (ListNode *)malloc(sizeof(ListNode));
  ListNode *third = (ListNode *)malloc(sizeof(ListNode));
  ListNode *fourth = (ListNode *)malloc(sizeof(ListNode));

  head->val = 1;
  first->val = 1;
  second->val = 3;
  third->val = 3;
  fourth->val = 5;

  head->next = first;
  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = NULL;

  Solution sol;
  sol.traverseLinkedList(head);
  head = sol.deleteDuplicates(head);
  sol.traverseLinkedList(head);   
    
          
          
return 0;
}