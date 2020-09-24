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
	Status DeleteSingleNode(RLNode*&, RLNode*&);
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

	RLink p = nullptr,
	    pre = nullptr;
	p = this->next;//ָ����Ԫ�ڵ�
	pre = this;//pre������pǰ

	while (this->next==tail)//ֻʣ��Ԫ�ڵ�(��ֹ����)
	{
	//�ҳ���������
		if (counter==killed)
		{
			//ɱ����
			DeleteSingleNode(pre,p);
			counter = 1;//���¼���
			continue;
		}
//TODO:���tail��ַ�ĸ�������
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

Status RLNode::DeleteSingleNode(RLNode *&Pre, RLNode *&Now)
{
	RLink Tmp = nullptr;//Э��ɾ���ڵ��ͷſռ�
	if (!Pre||!Now)
	{
		return ERROR;
	}
	Tmp = Now->next;//����˽ڵ�next�ڵ��ַ��Ϊ����󷵻ظ�Now��
	Pre->next = Tmp;
	delete Now;
	Now = Tmp;
	return OK;
}
