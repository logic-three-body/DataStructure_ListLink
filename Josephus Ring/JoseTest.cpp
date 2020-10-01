#include<iostream>
#include<new>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */


//constexpr int killed = 3;//�����ű�ɱ
typedef struct RLNode
{
private:
	Status data;
	RLNode *next;

	Status DeleteSingleNode(RLNode*&, RLNode*&, RLNode*&);//ɾ���ڵ㣬ɱ��
public:
	RLNode():next(nullptr) {};
	RLNode(ElemType a) :data(a), next(nullptr) {};
	Status CreateRingLink(int,RLNode*&,int *);
	Status JoseRing(RLNode*&,int killed);

}*RLink, //ͷָ��
RLNode,
*Tail;//βָ��
int main()
{

	//����棺
	int length = 0;
	int killed;//ɱ������
	std::cin >> length >> killed;
	while (length!=0&&killed!=0)
	{
		int* Youtai = new int[length];
		for (int i = 0; i < length; i++)
		{
			Youtai[i] = i + 1;
		}
		RLink rlist = new RLNode;
		Tail tail_ptr = nullptr;
		rlist->CreateRingLink(length, tail_ptr, Youtai);
		rlist->JoseRing(tail_ptr, killed);
		delete[] Youtai;
		std::cin >> length >> killed;
	}



	
	system("pause");
	return 0;
}
Status RLNode::CreateRingLink(int num, RLNode*& tail,int *Youptr)
{	
	//L = new(RLNode);	
	//L->next = new(RLNode(1));
	//L->next = new RLNode(1);
	if (num<=0)
	{
		return ERROR;
	}
	this->data = num;//ͷ�ڵ��������¼�ڵ�����
	int elem = 0;
	RLink p = nullptr;//β�巨ʵ��ѭ������
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

Status RLNode::JoseRing(RLNode*& tail, int killed)
{
	
	int counter = 1;//������




	RLink p = nullptr,
	    pre = nullptr;
	p = this->next;//ָ����Ԫ�ڵ�
	pre = this;//pre������pǰ

	while (this->next!=tail)//ֻʣ��Ԫ�ڵ�(��ֹ����)
	{
	//�ҳ���������
		if (counter==killed)
		{
			std::cout << p->data << " ";
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

	std::cout  << tail->data<<std::endl;

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
		Pre = Pre->next;//TODO:Is it correct?  Yes!
	}
	else
	{
	Now = Pre->next;
	}

	return OK;
}
