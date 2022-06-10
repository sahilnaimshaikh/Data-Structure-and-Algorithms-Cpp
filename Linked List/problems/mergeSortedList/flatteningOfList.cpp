#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if (list1->val >= list2->val)
            swap(list1, list2);
        ListNode *result = list1;

        while (list1 != NULL && list2 != NULL)
        {
            ListNode *temp = NULL;
            while (list1 != NULL && list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->bottom;
            }
            temp->bottom = list2;
            swap(list1, list2);
        }
        return result;
    }
class Solution
{
public:
  
    ListNode *flatten(ListNode *head)
    {
        if(head == NULL || head->next == NULL){
            return head;
        }
        head->next = flatten(head->next);
        head = mergeTwoLists(head,head->next);
        return head;
    }
    void traverseLinkedList(struct ListNode *ptr)
    {
        while (ptr != NULL)
        {
            cout << ptr->val << " ";
            ptr = ptr->bottom;
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

    ListNode *head1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *first1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *second1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *third1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *fourth1 = (ListNode *)malloc(sizeof(ListNode));

    ListNode *head3 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *first3 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *second3 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *third3 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *fourth3 = (ListNode *)malloc(sizeof(ListNode));

    head->val = 1;
    first->val = 2;
    second->val = 3;
    third->val = 4;
    fourth->val = 5;

    head->next = head1;
    head->bottom = first;
    first->bottom = second;
    second->bottom = third;
    third->bottom = fourth;
    fourth->bottom = NULL;

    head1->val = 3;
    first1->val = 7;
    second1->val = 9;
    third1->val = 11;
    fourth1->val = 19;

    head1->bottom = first1;
    head1->next = head3;
    first1->bottom = second1;
    second1->bottom = third1;
    third->bottom = fourth1;
    fourth1->bottom = NULL;

    head3->val = 13;
    first3->val = 14;
    second3->val = 19;
    third3->val = 111;
    fourth3->val = 119;

    head3->next = NULL;
    head3->bottom = first3;
    first3->bottom = second3;
    second3->bottom = third3;
    third3->bottom = fourth3;
    fourth3->bottom = NULL;

    Solution sol;
    head = sol.flatten(head);
    sol.traverseLinkedList(head);

    return 0;
}
// Time Complexity of this program is O(m+n) and Space Complexity is O(1).