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
    ListNode *d = (ListNode *)malloc(sizeof(ListNode));
    d->next = head;
    ListNode *s = d;
    ListNode *f = d;

    for (int i = 0; i < n; i++)
    {
      f = f->next;
    }
    if (f->next == NULL)
    {//if the above if condition is true that means the very first element is told to delete
      head = head->next;
    }
    else
    {
      while (f->next != NULL)
      {
        f = f->next;
        s = s->next;
      }
      s->next = s->next->next;
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
  head = sol.removeNthFromEnd(head, 5);
  sol.traverseLinkedList(head);

  return 0;
}