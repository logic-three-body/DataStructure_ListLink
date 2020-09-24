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
	RLNode():next(nullptr) {};
	RLNode(ElemType a) :data(a), next(nullptr) {};
	Status CreateRingLink(int,RLNode*&);
	Status JoseRing(RLNode*&);
	Status DeleteSingleNode(RLNode*&, RLNode*&, RLNode*& );
}*RLink, //头指针
RLNode,
*Tail;//尾指针
int main()
{
	int num = 0;


	std::cout << "输入元素个数" << std::endl;
	std::cin >> num;
	while (std::cin)
	{
	RLink rlist=new RLNode;
	Tail tail_ptr = nullptr;
	rlist->CreateRingLink(num,tail_ptr); 
	rlist->JoseRing(tail_ptr);
	std::cout << "输入元素个数" << std::endl;
	std::cin >> num;
	}
	system("pause");
	return 0;
}
Status RLNode::CreateRingLink(int num, RLNode*& t)
{	
	//L = new(RLNode);	
	//L->next = new(RLNode(1));
	//L->next = new RLNode(1);
	if (num<=0)
	{
		return ERROR;
	}

	int elem = 0;
	RLink p = nullptr;//尾插法实现循环链表
	RLink r = this;

	for (int i = 0; i < num; i++)
	{
		std::cin>>elem;
		p = new RLNode(elem);
		p->next = r->next;
		r->next = p;
		r = p;
	}
	t = r;
	r->next = this;
	return OK;
}

Status RLNode::JoseRing(RLNode*& tail)
{
	int killed = 3;//第三号被杀
	int counter = 1;//计数器


	//剧情版：
	int length = 41;
	int Youtai[41];
	for (int i = 0; i < length; i++)
	{
		Youtai[0] = i + 1;
	}

	RLink p = nullptr,
	    pre = nullptr;
	p = this->next;//指向首元节点
	pre = this;//pre保持在p前

	while (this->next!=tail)//只剩守元节点(中止条件)
	{
	//找出三号人物
		if (counter==killed)
		{
			std::cout << "Kills Number " << p->data << std::endl;
			//杀死他
			DeleteSingleNode(pre,p,tail);
			counter = 1;//重新计数
			continue;
		}

//TODO:解决Delete函数中P指向头节点的问题
	


	//遍历
		if (p==tail)//如果已经到末尾
		{
			p = tail->next->next; //指向首元节点
			pre = tail->next;//pre保持在p前
		}
		else
		{
		p = p->next;
		pre = pre->next;
		}
		++counter;//继续报数
	}

	

	return OK;
}

Status RLNode::DeleteSingleNode(RLNode *&Pre, RLNode *&Now, RLNode*& Tail_Ptr)
{
	RLink Tmp = nullptr;//协助删除节点释放空间
	if (!Pre||!Now)
	{
		return ERROR;
	}
	Tmp = Now->next;//保存此节点next节点地址（为了最后返回给Now）
	if (Now==Tail_Ptr)
	{
	 Tail_Ptr = Pre;//尾指针前移
	}
	Pre->next = Tmp;
	delete Now;
	if (Pre==Tail_Ptr)//解决Delete函数中P指向头节点的问题
	{
		Now = Pre->next->next;
	}
	else
	{
	Now = Pre->next;
	}

	return OK;
}
