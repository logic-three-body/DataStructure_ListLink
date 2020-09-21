#define FILE_BUFFER_LENGTH 30000
#include<iostream>
#include<stdlib.h>
/**
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

				//p = nullptr;
				//delete p;  //释放空间

				//free(p);

				//ptr = nullptr;
				//delete ptr;
				//ptr = p->next;



			}
			else
			{
				ptr = ptr->next;  //移动到后一个元素
			}
		}
		return head;  //返回首个节点
	}
};


class Solution2 {//access in leetcode
public:
	ListNode* deleteDuplicates(ListNode* head) {

		if (!head)
			return head;
		

		// define a dummy(king) node in case delete the head node
		// dummy.next=head		
		ListNode*dummy = new ListNode(NULL);
		//two pointer : a king and a soilder,soilder to seek object and help king catch object		
		dummy->next = head;
		ListNode*soilder = dummy->next;
		head = dummy;
		// correct if dummy is unnecessary
		while (soilder&&soilder->next)
		{
			if (dummy->next->val == soilder->next->val)
			{
				int rec_num=soilder->val;
				while (soilder->next&&soilder->val==soilder->next->val)
				{
					soilder = soilder->next;
				}
				dummy->next = soilder->next;
				soilder = dummy->next;
			}
			else
			{
				dummy = dummy->next;
				soilder = soilder->next;
			}

		}
		//delete dummy;

		return head->next;
	}
};
class Solution4 {//access in leetcode
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* PCUR = new ListNode(0);
		PCUR->next = head;
		head = PCUR;
		ListNode *L, *R;
		while (PCUR->next != NULL)
		{
			L = PCUR->next;
			R = PCUR->next;
			while (R->next && R->next->val == L->val)
				R = R->next;
			//如果循环后，L与R节点相同，说明不重复
			if (L == R) PCUR = PCUR->next;
			//L与R节点不相同，将PCUR的next指向R->next,继续重复上述操作
			else
			{
				PCUR->next = R->next;
				//TODO 释放失败 C++没有内存回收机制，应该释放这些指针，虽然不释放能通过，但是应该养成好习惯
				while (L != R)
				{
					ListNode*tmp = L;
					L = L->next;
					delete tmp;
				}
				//TODO 释放失败
				delete L;
			}
		}
		return head->next;
	}
};



int main()
{
	ListNode test1(1), test2(1), test3(3), test4(3), test5(4), test6(4), test7(5), test8(6);
	ListNode* head = new ListNode(1);
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
	//cout<<(test1.next)<<endl;
	//cout << test1.next->val<<endl;
	//cout << &(test1.next->val) << endl;
	//cout << head << endl;
	//cout << &head << endl;
	//cout << head->next << endl;

	Solution3 app3;
	Solution2 app2;
	Solution4 app4;
	//app2.deleteDuplicates(head2);
	//app3.deleteDuplicates(head);
	app3.deleteDuplicates(head);
	//app.deleteDuplicates(head);
	delete head;
	system("pause");
	return 0;
}