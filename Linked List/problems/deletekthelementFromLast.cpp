#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    int i = 1, N;
    ListNode *d = head;
    while (d->next != NULL)
    {
      d = d->next;
      i++;
    }
     d= head; // again assigning head to d;
    N = i - n;
    i = 1;
    if (N != 0)
    {
      while (N != i)
      {
        d = d->next;
        i++;
      }
      d->next = d->next->next;
    }
    else
    {
      head = head->next;
    }
    return head;
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

int main()
{

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

  Solution sol;
  sol.traverseLinkedList(head);
  head = sol.removeNthFromEnd(head, 2);
  sol.traverseLinkedList(head);

  return 0;
}