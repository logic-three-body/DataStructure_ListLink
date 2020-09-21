#include<iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};



int main()
{
	ListNode test1(2), test2(3), test3(3), test4(3), test5(3), test6(4), test7(4), test8(5);
	ListNode* head = new ListNode(0);
	ListNode*head2 = nullptr;
	head->next = &test1;
	test1.next = &test2;
	test2.next = &test3;
	test3.next = &test4;
	test4.next = &test5;
	test5.next = &test6;
	test6.next = &test7;
	test7.next = &test8;
}