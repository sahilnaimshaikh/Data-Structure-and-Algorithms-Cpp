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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if(list1 ==NULL)return list2;
        if(list2 ==NULL)return list1;

        if(list1->val >= list2->val) swap(list1,list2);
        ListNode * result = list1;

        while(list1 != NULL && list2 != NULL){
            ListNode * temp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return result;
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

    ListNode *head1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *first1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *second1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *third1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *fourth1 = (ListNode *)malloc(sizeof(ListNode));

    head1->val = 3;
    first1->val = 7;
    second1->val = 9;
    third1->val = 11;
    fourth1->val = 19;

    head1->next = first1;
    first1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = NULL;

    Solution sol;
    head = sol.mergeTwoLists(head, head1);
    sol.traverseLinkedList(head);

    return 0;
}
// Time Complexity of this program is O(m+n) and Space Complexity is O(1).