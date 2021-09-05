#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


  //Definition for singly-linked list.
 //struct ListNode {
 //     int val;
 //     ListNode *next;
 //     ListNode() : val(0), next(nullptr) {}
 //     ListNode(int x) : val(x), next(nullptr) {}
 //     ListNode(int x, ListNode *next) : val(x), next(next) {}
 // };

 
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
  ListNode* pHead = NULL;  //指向链表的头节点
  ListNode* pTail = NULL;  //指向链表的尾节点

  ListNode *CreateList(int val)
  {
      ListNode* tmp = (ListNode * )malloc(sizeof(ListNode));
      tmp->val = val;//(*tmp).no = no;两种写法等效
      tmp->next = NULL;  //至此一块空间已经被创建好了

      //二：连接链表
      if (pHead == NULL)  //可以判断这个链表是第一个节点
      {
          pHead = tmp;  //把tmp值拿出来放在pHead里面
      }
      else
      {
          pTail->next = tmp;
      }
      pTail = tmp;
      return tmp;
  }

 
  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
      struct ListNode* head = NULL, * tail = NULL;
      int carry = 0;
      while (l1 || l2) {
          int n1 = l1 ? l1->val : 0;
          int n2 = l2 ? l2->val : 0;
          int sum = n1 + n2 + carry;
          if (!head) {
              head = tail = (ListNode*)malloc(sizeof(struct ListNode));
              tail->val = sum % 10;
              tail->next = NULL;
          }
          else {
              tail->next = (ListNode *)malloc(sizeof(struct ListNode));
              tail->next->val = sum % 10;
              tail = tail->next;
              tail->next = NULL;
          }
          carry = sum / 10;
          if (l1) {
              l1 = l1->next;
          }
          if (l2) {
              l2 = l2->next;
          }
      }
      if (carry > 0) {
          tail->next = (ListNode*)malloc(sizeof(struct ListNode));
          tail->next->val = carry;
          tail->next->next = NULL;
      }
      return head;
  }

  void PrintList()
  {
      ListNode* t = pHead;
      while (t)
      {
          printf("val值：", t->next);
          t = t->next;
      }
  }

int main()
{
    ListNode * a= addTwoNumbers(CreateList(4), CreateList(3));
    printf("%d\n:", a->val);
    return 0;


}