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
	Status JoseRing(RLNode*&);
	Status DeleteSingleNode(RLNode*&, RLNode*&, RLNode*& );
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
	rlist->JoseRing(tail_ptr);
	std::cout << "����Ԫ�ظ���" << std::endl;
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

Status RLNode::JoseRing(RLNode*& tail)
{
	int killed = 3;//�����ű�ɱ
	int counter = 1;//������


	//����棺
	int length = 41;
	int Youtai[41];
	for (int i = 0; i < length; i++)
	{
		Youtai[0] = i + 1;
	}

	RLink p = nullptr,
	    pre = nullptr;
	p = this->next;//ָ����Ԫ�ڵ�
	pre = this;//pre������pǰ

	while (this->next!=tail)//ֻʣ��Ԫ�ڵ�(��ֹ����)
	{
	//�ҳ���������
		if (counter==killed)
		{
			std::cout << "Kills Number " << p->data << std::endl;
			//ɱ����
			DeleteSingleNode(pre,p,tail);
			counter = 1;//���¼���
			continue;
		}

//TODO:���Delete������Pָ��ͷ�ڵ������
	


	//����
		if (p==tail)//����Ѿ���ĩβ
		{
			p = tail->next->next; //ָ����Ԫ�ڵ�
			pre = tail->next;//pre������pǰ
		}
		else
		{
		p = p->next;
		pre = pre->next;
		}
		++counter;//��������
	}

	

	return OK;
}

Status RLNode::DeleteSingleNode(RLNode *&Pre, RLNode *&Now, RLNode*& Tail_Ptr)
{
	RLink Tmp = nullptr;//Э��ɾ���ڵ��ͷſռ�
	if (!Pre||!Now)
	{
		return ERROR;
	}
	Tmp = Now->next;//����˽ڵ�next�ڵ��ַ��Ϊ����󷵻ظ�Now��
	if (Now==Tail_Ptr)
	{
	 Tail_Ptr = Pre;//βָ��ǰ��
	}
	Pre->next = Tmp;
	delete Now;
	if (Pre==Tail_Ptr)//���Delete������Pָ��ͷ�ڵ������
	{
		Now = Pre->next->next;
	}
	else
	{
	Now = Pre->next;
	}

	return OK;
}
