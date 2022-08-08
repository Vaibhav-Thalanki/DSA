/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// ITERATIVE:
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;

        ListNode *t;
        ListNode *prev = NULL;
        while (cur != NULL)
        {
            t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        return prev;
    }
};

// RECURSIVE

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
        {
            return head;
        }

        ListNode *t = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return t;
    }
};