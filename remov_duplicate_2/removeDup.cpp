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
 �˴�׫д����˼·��

 ע���߼��������&&����������
 current->next&&current����ͨ��access within null pointer
 current&&current->next �� ͨ��

 ԭ��nullptr�޷����룬ǰ���ȶ�ȡcurrent->next��ȡʧ�ܣ����벻ͨ��

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
		if (head == NULL)  //�����������Ϊ��ֱ�ӷ��أ�������ִ��ptr->next�ⲿ����ʱ����ΪptrΪNULL�����ִ��ʱ����
			return head;
		ListNode* ptr{ head };  //������ָ��
		while (ptr->next != NULL)  //�����׸�Ԫ�ص��ڵ����ڶ���Ԫ�أ���Ϊ��������Ƚϣ����һ��Ԫ�ػᱻ�Ƚϵ�����������ȷ��
		{
			if (ptr->val == ptr->next->val)  //�ͺ�һ��Ԫ�رȽ�
			{
				ListNode* p = ptr->next;
				ptr->next = p->next;  //ɾ������
				delete p;  //�ͷſռ�
			}
			else
			{
				ptr = ptr->next;  //�ƶ�����һ��Ԫ��
			}
		}
		return head;  //�����׸��ڵ�
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