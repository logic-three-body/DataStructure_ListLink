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

				//p = nullptr;
				//delete p;  //�ͷſռ�

				//free(p);

				//ptr = nullptr;
				//delete ptr;
				//ptr = p->next;



			}
			else
			{
				ptr = ptr->next;  //�ƶ�����һ��Ԫ��
			}
		}
		return head;  //�����׸��ڵ�
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
			//���ѭ����L��R�ڵ���ͬ��˵�����ظ�
			if (L == R) PCUR = PCUR->next;
			//L��R�ڵ㲻��ͬ����PCUR��nextָ��R->next,�����ظ���������
			else
			{
				PCUR->next = R->next;
				//TODO �ͷ�ʧ�� C++û���ڴ���ջ��ƣ�Ӧ���ͷ���Щָ�룬��Ȼ���ͷ���ͨ��������Ӧ�����ɺ�ϰ��
				while (L != R)
				{
					ListNode*tmp = L;
					L = L->next;
					delete tmp;
				}
				//TODO �ͷ�ʧ��
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