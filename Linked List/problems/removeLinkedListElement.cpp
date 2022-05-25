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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode * dummy = (ListNode*)malloc(sizeof(ListNode));
        dummy->next = head;
        ListNode * temp = dummy;
       while(temp->next !=NULL){
           if(temp->next->val == val){
               temp->next = temp->next->next;
           }else{ temp = temp->next;}
       }
       
       return dummy->next;
        
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
    third->val = 2;
    fourth->val = 2;

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    Solution sol;
    sol.traverseLinkedList(head);
    // head = sol.removeElements(head, 2);
    sol.traverseLinkedList(sol.removeElements(head, 2));

    return 0;
}