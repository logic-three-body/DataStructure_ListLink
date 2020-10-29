#define FILE_BUFFER_LENGTH 30000//List Remove Duplicate Node
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

//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/\

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* current = head;
		ListNode *temp = head ;//作为交换变量
		while (current->next&&current)//排除nullptr
		{
			if (current->val == current->next->val)
			{	
				//temp = current;
				//temp=current->next;
				current->next = current->next->next;
				//temp->next->next = nullptr;//清理野指针，我不要你这个节点你tnd就哪也别指
				//temp->next = nullptr;//清理野指针，我不要你这个节点你tnd就哪也别指



				//current->next->next = nullptr;//清理野指针，我不要你这个节点你tnd就哪也别指
				//current->next = current->next->next;

			}
			else
				current = current->next;
		}

		return head;
	}

};

class Solution2 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* current = head;
		//ListNode *temp{head};//作为交换变量
		//while (current->next&&current)//排除nullptr
		while (current&&current->next)//排除nullptr
		{
			if (current->val == current->next->val)
			{
				//ListNode *temp{ head };//作为交换变量
				ListNode *temp = current->next;//作为交换变量
				current->next = temp->next;
				//current->next = nullptr;
				delete temp;

			}
			else
				current = current->next;
		}

		return head;
	}

};

//class Solution3 {
//public:
//	ListNode* deleteDuplicates(ListNode* head)
//	{
//		if (head == NULL)  //如果所给链表为空直接返回，否则在执行ptr->next这部操作时会因为ptr为NULL而造成执行时错误
//			return head;
//		ListNode* ptr{ head };  //遍历的指针
//		while (ptr->next != NULL)  //遍历首个元素到第倒数第二个元素，因为是逐个向后比较，最后一个元素会被比较到，这样是正确的
//		{
//			if (ptr->val == ptr->next->val)  //和后一个元素比较
//			{
//				ListNode* p = ptr->next;
//				ptr->next = p->next;  //删除操作
//				delete p;  //释放空间
//				//free(p);
//			}
//			else
//			{
//				ptr = ptr->next;  //移动到后一个元素
//			}
//		}
//		return head;  //返回首个节点
//	}
//};

class Solution4 {//双指针
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* p = head;//慢指针
		ListNode* q = head->next;//快指针
		while (p->next != NULL)
		{
			if (p->val == q->val)//找到重复元素
			{
				if (q->next == NULL)//快指针后面若没有元素直接剔除
					p->next = NULL;
				else//快指针后有元素
				{
					p->next = q->next;
					q = q->next;
				}
			}
			else //元素不相等
			{
				p = p->next;
				q = q->next;
			}
		}
		return head;
	}
};

class Solution5 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
			return head;
		head->next = deleteDuplicates(head->next);
		if (head->val == head->next->val) head = head->next;
		return head;
	}
};




int main()
{
	ListNode test1(2),test2(3),test3(3),test4(3),test5(3),test6(4),test7(4),test8(5);
	ListNode* head=new ListNode(0);
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
	//Solution app;
	//Solution2 app2;
	//Solution3 app3;
	
	//app2.deleteDuplicates(head2);
	//app3.deleteDuplicates(head);
	//app2.deleteDuplicates(head);
	//app.deleteDuplicates(head);

	Solution4 app4;
	//app4.deleteDuplicates(head);

	Solution5 app5;
	app5.deleteDuplicates(head);
	
	delete head;
	system("pause");
	return 0;
}