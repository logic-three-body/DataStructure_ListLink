#include<iostream>
#include<new>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */
typedef struct RLNode
{
private:
	Status data;
	RLNode *next;
public:
	RLNode() :next(nullptr) {};
	RLNode(ElemType a) :data(a), next(nullptr) {};
	Status CreateRingLink(int, RLNode*&, int *);
	Status JoseRing(RLNode*&);
	Status DeleteSingleNode(RLNode*&, RLNode*&, RLNode*&);
}*RLink, //头指针
RLNode,
*Tail;//尾指针

int main()
{
	//剧情版：
	int length = 41;
	int Youtai[41];
	for (int i = 0; i < length; i++)
	{
		Youtai[i] = i + 1;
	}
	RLink rlist = new RLNode;
	Tail tail_ptr = nullptr;
	rlist->CreateRingLink(length, tail_ptr, Youtai);
}



Status RLNode::CreateRingLink(int num, RLNode*& t, int *Youptr)
{
	//L = new(RLNode);	
	//L->next = new(RLNode(1));
	//L->next = new RLNode(1);
	if (num <= 0)
	{
		return ERROR;
	}

	int elem = 0;
	RLink p = nullptr;//尾插法实现循环链表
	RLink r = this;

	for (int i = 0; i < num; i++)
	{
		elem = Youptr[i];
		p = new RLNode(elem);
		p->next = r->next;
		r->next = p;
		r = p;
	}
	t = r;
	r->next = this;
	return OK;
}