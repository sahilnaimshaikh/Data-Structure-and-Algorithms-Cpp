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
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
      ListNode * d = (ListNode*)malloc(sizeof(ListNode));
      ListNode* temp = d;
      int carry = 0;
      while (l1 != NULL || l2!=NULL || carry!=0)
      {     int sum = 0;
          if(l1!=NULL){
              sum += l1->val;
              l1 = l1->next;
          }
          if(l2!=NULL){
              sum += l2->val;
              l2 = l2->next;
          }
          sum+= carry;
          carry = 0;
          carry = (sum/10);
          ListNode * node = (ListNode *)malloc(sizeof(ListNode));
          node->val =(sum%10);
          node->next = NULL;
          temp->next = node;
          temp = temp->next;
          
      }
      return d->next;
        
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
  ListNode *third1 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *fourth1 = (ListNode *)malloc(sizeof(ListNode));

  head1->val = 3;
  first1->val = 7;
  second1->val = 3;
  third1->val = 1;
  fourth1->val = 9;

  head1->next = first1;
  first1->next = second1;
  second1->next = third1;
  third1->next = fourth1;
  fourth1->next = NULL;         
    
Solution sol;
  sol.traverseLinkedList(head);
  sol.traverseLinkedList(head1);
  ListNode * result = sol.addTwoNumbers(head, head1);
  sol.traverseLinkedList(result);
          
return 0;
}