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
�˴�׫д����˼·��

ע���߼��������&&����������
current->next&&current����ͨ��access within null pointer
current&&current->next �� ͨ��

ԭ��nullptr�޷����룬ǰ���ȶ�ȡcurrent->next��ȡʧ�ܣ����벻ͨ��

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
		ListNode *temp = head ;//��Ϊ��������
		while (current->next&&current)//�ų�nullptr
		{
			if (current->val == current->next->val)
			{	
				//temp = current;
				//temp=current->next;
				current->next = current->next->next;
				//temp->next->next = nullptr;//����Ұָ�룬�Ҳ�Ҫ������ڵ���tnd����Ҳ��ָ
				//temp->next = nullptr;//����Ұָ�룬�Ҳ�Ҫ������ڵ���tnd����Ҳ��ָ



				//current->next->next = nullptr;//����Ұָ�룬�Ҳ�Ҫ������ڵ���tnd����Ҳ��ָ
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
		//ListNode *temp{head};//��Ϊ��������
		//while (current->next&&current)//�ų�nullptr
		while (current&&current->next)//�ų�nullptr
		{
			if (current->val == current->next->val)
			{
				//ListNode *temp{ head };//��Ϊ��������
				ListNode *temp = current->next;//��Ϊ��������
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
//		if (head == NULL)  //�����������Ϊ��ֱ�ӷ��أ�������ִ��ptr->next�ⲿ����ʱ����ΪptrΪNULL�����ִ��ʱ����
//			return head;
//		ListNode* ptr{ head };  //������ָ��
//		while (ptr->next != NULL)  //�����׸�Ԫ�ص��ڵ����ڶ���Ԫ�أ���Ϊ��������Ƚϣ����һ��Ԫ�ػᱻ�Ƚϵ�����������ȷ��
//		{
//			if (ptr->val == ptr->next->val)  //�ͺ�һ��Ԫ�رȽ�
//			{
//				ListNode* p = ptr->next;
//				ptr->next = p->next;  //ɾ������
//				delete p;  //�ͷſռ�
//				//free(p);
//			}
//			else
//			{
//				ptr = ptr->next;  //�ƶ�����һ��Ԫ��
//			}
//		}
//		return head;  //�����׸��ڵ�
//	}
//};

class Solution4 {//˫ָ��
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* p = head;//��ָ��
		ListNode* q = head->next;//��ָ��
		while (p->next != NULL)
		{
			if (p->val == q->val)//�ҵ��ظ�Ԫ��
			{
				if (q->next == NULL)//��ָ�������û��Ԫ��ֱ���޳�
					p->next = NULL;
				else//��ָ�����Ԫ��
				{
					p->next = q->next;
					q = q->next;
				}
			}
			else //Ԫ�ز����
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
	//test1.next->val = 1;//�쳣
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