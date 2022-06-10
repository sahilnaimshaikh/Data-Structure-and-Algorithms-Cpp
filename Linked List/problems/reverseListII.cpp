// intuition behind the below code is that we will connect the (left-1)th  node to the (right)th node and (left)th node to right->next node.

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
     ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(head == NULL || head->next == NULL) return head; // return if only one node is present;


         ListNode * p = new ListNode();
         p->next = head;// make p as a previous node of head;

        ListNode * leftPos = p;
        ListNode * rightPos = p;

// step 1 : find the (left-1)th  node .
        for (int i = 1; i < left; i++)
        {
            leftPos = leftPos->next;
        }
// step 2 : find the (right)th node .        
        for (int  i = 0; i < right; i++)
        {
            rightPos = rightPos->next;
        }
       
        ListNode * dummy = leftPos->next;

        leftPos->next = rightPos; // connecting (left)th node to (right)th node
        
        ListNode * d = rightPos->next;
        ListNode * d1 = rightPos->next;
        while (dummy != d1)
        {
            ListNode * dummy1 = dummy->next;
            dummy->next = d;
            d = dummy;
            dummy = dummy1;
        }
        return p->next;
  
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
//   second->val = 3;
//   third->val = 4;
//   fourth->val = 5;

  head->next = first;
  first->next = NULL;
//   second->next = third;
//   third->next = fourth;
//   fourth->next = NULL;

  Solution sol;
  sol.traverseLinkedList(head);
  head = sol.reverseBetween(head, 1,2);
  sol.traverseLinkedList(head);   
    
          
          
return 0;
}