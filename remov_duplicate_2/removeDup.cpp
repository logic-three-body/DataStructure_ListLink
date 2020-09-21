#include<iostream>
#include<stdlib.h>

/**
 *https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
 此处撰写解题思路：

 注意逻辑运算规律&&：从左向右
 current->next&&current：不通过access within null pointer
 current&&current->next ： 通过

 原因：nullptr无法读入，前者先读取current->next读取失败，编译不通过

 */
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};



class Solution3 {
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == NULL)  //如果所给链表为空直接返回，否则在执行ptr->next这部操作时会因为ptr为NULL而造成执行时错误
			return head;
		ListNode* ptr{ head };  //遍历的指针
		while (ptr->next != NULL)  //遍历首个元素到第倒数第二个元素，因为是逐个向后比较，最后一个元素会被比较到，这样是正确的
		{
			if (ptr->val == ptr->next->val)  //和后一个元素比较
			{
				ListNode* p = ptr->next;
				ptr->next = p->next;  //删除操作
				delete p;  //释放空间
			}
			else
			{
				ptr = ptr->next;  //移动到后一个元素
			}
		}
		return head;  //返回首个节点
	}
};



int main()
{
	ListNode test1(1), test2(1), test3(3), test4(3), test5(4), test6(4), test7(5), test8(6);
	ListNode* head = new ListNode(1);
	ListNode*head2 = nullptr;
	head->next = &test1;
	test1.next = &test2;
	test2.next = &test3;
	test3.next = &test4;
	test4.next = &test5;
	test5.next = &test6;
	test6.next = &test7;
	test7.next = &test8;


	Solution3 app3;

	app3.deleteDuplicates(head);

	delete head;
	system("pause");
	return 0;
}