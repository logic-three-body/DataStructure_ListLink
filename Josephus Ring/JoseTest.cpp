#include<iostream>
#include<new>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */
typedef struct RLNode
{
private:
	Status data;
	RLNode *next;
public:
	RLNode():next(nullptr) {};
	RLNode(ElemType a) :data(a), next(nullptr) {};
	Status CreateRingLink(int,RLNode*&);
	Status JoseRing(int, RLNode*&);
}*RLink, //ͷָ��
RLNode,
*Tail;//βָ��
int main()
{
	int num = 0;
	std::cout << "����Ԫ�ظ���" << std::endl;
	std::cin >> num;
	while (std::cin)
	{
	RLink rlist=new RLNode;
	Tail tail_ptr = nullptr;
	rlist->CreateRingLink(num,tail_ptr); 
	int kill_someone = 3;
	rlist->JoseRing(kill_someone, tail_ptr);
	std::cout << "����Ԫ�ظ���" << std::endl;
	std::cin >> num;
	}
	system("pause");
	return 0;
}
Status RLNode::CreateRingLink(int num,Tail&t)
{	
	//L = new(RLNode);	
	//L->next = new(RLNode(1));
	//L->next = new RLNode(1);
	if (num<=0)
	{
		return ERROR;
	}

	int elem = 0;
	RLink p = nullptr;//β�巨ʵ��ѭ������
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

Status RLNode::JoseRing(int killed, Tail& t)
{
	if (killed<=0)
	{
		return ERROR;
	}

	return OK;
}
