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
    bool isPalindrome(ListNode *head)
    {
        if (head->next == NULL)
            return true;

        ListNode *s = head;
        ListNode *f = head;
        while (f->next != NULL && f->next->next != NULL)
        {
            s = s->next;
            f = f->next->next;
        } // middle of the linked list has been found as s;
        ListNode *dummy = s->next;

        ListNode *n = NULL;

        while (dummy->next != NULL)
        {
            ListNode *dummy2 = dummy->next;
            dummy->next = n;

            n = dummy;
            dummy = dummy2;
        }
        s->next = dummy;
        dummy->next = n;
        // the second half of the linked list has been reversed;

        ListNode *h = head;
        s = s->next;
        while (s != NULL)
        {
            if (s->val != h->val)
                return false;
            s = s->next;
            h = h->next;
        }

        return true;
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
    // ListNode *first = (ListNode *)malloc(sizeof(ListNode));
    // ListNode *second = (ListNode *)malloc(sizeof(ListNode));
    // ListNode *third = (ListNode *)malloc(sizeof(ListNode));
    // ListNode *fourth = (ListNode *)malloc(sizeof(ListNode));

    head->val = 1;
    // first->val = 2;
    // second->val = 3;
    // third->val = 2;
    // fourth->val = 1;

    head->next = NULL;
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = NULL;

    Solution sol;
    // sol.traverseLinkedList(head);
    cout << sol.isPalindrome(head);
    // sol.traverseLinkedList(head);

    return 0;
}