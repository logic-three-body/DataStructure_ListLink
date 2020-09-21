#include<iostream>
#include<stdlib.h>
/**
 *https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
  此处撰写解题思路：

  注意逻辑运算规律&&：从左向右
  current->next&&current：不通过access within null pointer
  current&&current->next ： 通过

  原因：nullptr无法读入，前者先读取current->next读取失败，编译不通过

  */
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode *p = head;
		while (p->next != NULL)
		{
			if (p->val != p->next->val)
			{
				p = p->next;
			}
			else
			{
				if (p->next->next == NULL)
				{
					ListNode *s = p->next;
					delete s;
					p->next = NULL;
				}
				else
				{
					ListNode *s = p->next;
					p->next = s->next;
					ListNode*tmp = s;
					cout << s<<endl;
					cout << s->val<<endl;
					//free(tmp);
					
					//ListNode *s = p;
					//p = p->next->next;
					//delete s->next;
				}
			}
		}
		return head;
	}
};
int main()
{
	ListNode test1(2), test2(3), test3(3), test4(3), test5(3), test6(4), test7(4), test8(5);
	ListNode* head = new ListNode(0);
	ListNode*head2 = nullptr;
	//test1.next->val = 1;//异常
	//test1.next->next->val = 1;
	//test1.next = test1.next->next;
	head->next = &test1;
	test1.next = &test2;
	test2.next = &test3;
	test3.next = &test4;
	test4.next = &test5;
	test5.next = &test6;
	test6.next = &test7;
	test7.next = &test8;
	Solution app;
	app.deleteDuplicates(head);

	delete head;
	system("pause");
	return 0;
}