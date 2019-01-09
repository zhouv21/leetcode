//problem 2
//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//将这两个数相加起来，返回一个新的链表来表示它们的和。

#include <stdio.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(0);
        ListNode *p = l1, *q = l2;
        ListNode *cur = result;
        int carry = 0;
        while (p != NULL || q != NULL)
        {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = x + y + cur->val;
            cur->val = sum % 10;
            carry = sum / 10;
            if (p)
                p = p->next;
            if (q)
                q = q->next;
            if (carry > 0)
                cur->next = new ListNode(carry);
            else if (p || q)
                cur->next = new ListNode(0);

            cur = cur->next;
        }

        return result;
    }
};

void printIntegerList(ListNode *l)
{
    while (l)
    {
        printf("%d", l->val);
        if (l->next)
            printf(" -> ");
        l = l->next;
    }
}

void deleteIntegerList(ListNode *l)
{
    while (l)
    {
        ListNode *p = l->next;
        delete l;
        l = p;
    }
}

int main()
{
    while (1)
    {
        printf("enter the first integer in reverse order:");
        ListNode *l1 = NULL;
        ListNode *p = NULL;
        ;
        int val = 0;
        while (scanf("%d", &val))
        {
            ListNode *l = new ListNode(val);
            if (!l1)
            {
                l1 = l;
                p = l1;
            }
            else
            {
                p->next = l;
                p = p->next;
            }

            if (getchar() == '\n')
                break;
        }

        printf("\nlist of first integer: ");
        printIntegerList(l1);
        printf("\nenter the second integer in reverse order:");
        ListNode *l2 = NULL;
        p = l2;
        while (scanf("%d", &val))
        {
            ListNode *l = new ListNode(val);
            if (!l2)
            {
                l2 = l;
                p = l2;
            }
            else
            {
                p->next = l;
                p = p->next;
            }

            if (getchar() == '\n')
                break;
        }
        printf("\nlist of second integer: ");
        printIntegerList(l2);

        Solution s;
        ListNode *result = s.addTwoNumbers(l1, l2);
        printf("\nresult:");
        printIntegerList(result);

        deleteIntegerList(l1);
        deleteIntegerList(l2);
        deleteIntegerList(result);

        printf("\n\nenter 0 to stop, otherwise continue\n");
        int stop = 0;
        scanf("%d", &stop);

        if (!stop)
            break;
    }

    return 0;
}