/*􀘃􁦡
思路：用递归规律直接定位到要删除的节点而不用一次次遍历寻找
help:程序员内功修炼P166-167􀔅
*/



#include<iostream>
#include<new>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

constexpr int length = 8;
constexpr int killed = 3;//第三号被杀

typedef struct RLNode
{
private:
	Status data;
	RLNode *next;

	int JoseKillNum(int, int) const;//递归函数，直接返回要杀的人
	Status DeleteSingleNode(RLNode*&, RLNode*&, RLNode*&);
public:
	RLNode() :next(nullptr) {};
	RLNode(ElemType a) :data(a), next(nullptr) {};
	Status CreateRingLink(int, RLNode*&, int *);
	Status JoseRing();

}*RLink, //头指针
RLNode,
*Tail;//尾指针
int main()
{
	//剧情版：
	int Youtai[length];
	for (int i = 0; i < length; i++)
	{
		Youtai[i] = i + 1;
	}
	RLink rlist = new RLNode;
	Tail tail_ptr = nullptr;
	rlist->CreateRingLink(length, tail_ptr, Youtai);
	rlist->JoseRing();
	system("pause");
	return 0;
}

Status RLNode::JoseRing()
{
	int total = this->data;//头节点保存着数据总数
	//int des = JoseKillNum(total,killed);//目标编号
	int des = 1;
	

	return OK;
}

int RLNode::JoseKillNum(int Total,int Num) const//总人数，要杀的人的编号
{
	if (1==Total)
	{
		return 1;
	}
	return
		(JoseKillNum(Total - 1, Num) + Num - 1) % Total + 1;
}

Status RLNode::CreateRingLink(int num, RLNode*& tail, int *Youptr)
{
	if (num <= 0)
	{
		return ERROR;
	}
	this->data = num;
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
	tail = r;
	r->next = this;
	return OK;
}

Status RLNode::DeleteSingleNode(RLNode *&Pre, RLNode *&Now, RLNode*& Tail_Ptr)
{
	RLink Tmp = nullptr;//协助删除节点释放空间
	if (!Pre || !Now)
	{
		return ERROR;
	}
	Tmp = Now->next;//保存此节点next节点地址（为了最后返回给Now）
	if (Now == Tail_Ptr)
	{
		Tail_Ptr = Pre;//尾指针前移
	}
	Pre->next = Tmp;
	delete Now;
	if (Pre == Tail_Ptr)//解决Delete函数中P指向头节点的问题
	{
		Now = Pre->next->next;
		Pre = Pre->next;//TODO:Is it correct?  Yes!
	}
	else
	{
		Now = Pre->next;
	}
	return OK;
}