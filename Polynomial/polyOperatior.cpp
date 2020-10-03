#include<iostream>
#include<string>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */

//HELP�����ݽṹ��P48
typedef struct PNode
{
private:
	float coefficent;
	int exponent;
public:
	PNode() :next(nullptr) {};//��ʼ��������
	PNode(int num);//��ʼ��������
	Status AddPoly( PNode*&Pb);//���
	Status OutPutPoly();
	PNode*next;
}*Polynomial;


int main()
{
	int num;
	std::cin >> num;
	while (num--)
	{
		int terms1, terms2;
		std::cin >> terms1 >> terms2;
	    Polynomial polyA = new PNode(terms1);
	    Polynomial polyB = new PNode(terms2);
		std::string choice; 
		std::cin >> choice;
		if (choice == "+")
		{
			polyA->AddPoly(polyB);
			polyA->OutPutPoly();
		}
		if (choice == "-");
		if (choice == "*");
		if (choice == "'") {

		}
	}

	
	return 0;
}


PNode::PNode(int num):next(nullptr)
{
	Polynomial pre = nullptr;
	Polynomial q = nullptr;
	for (int i = 0; i < num; i++)
	{
		pre = this;
		q = pre->next;

		Polynomial s = new PNode;
		std::cin >> s->coefficent >> s->exponent;
		while (q&&q->exponent>s->exponent)//ͨ���Ƚϵ�һ������������ָ������*q
		{
			pre = q;
			q = q->next;
		}
		//����(pre->  -> s ->q)
		s->next = q;
		pre->next = s;

		//ǰ��

	}
}

Status PNode::AddPoly( PNode *& Pb)//Pa(this)+Pb
{
	if (!Pb&&!Pb->next)
	{
		return ERROR;
	}

	Polynomial p1 = this->next;
	Polynomial p2 = Pb->next;
	Polynomial Pnow = this;
	Polynomial tmp = nullptr;
	int sum = 0;//������ϵ����

	while (p1&&p2)
	{
		if (p1->exponent==p2->exponent)
		{
			sum = p1->coefficent + p2->coefficent;//����ϵ����
			if (sum)
			{
				p1->coefficent = sum;//�޸�ԭ��������(��ǰ�ڵ�)ϵ��
				Pnow->next = p1;
				Pnow = p1;
				p1 = p1->next;
				//ɾ��pb�ڵ㣬���տռ�
				tmp = p2;
				p2 = p2->next;
				delete tmp;				
			}
			else
			{
				//ɾ��this�ڵ㣬���տռ�
				tmp = p1;
				p1 = p1->next;
				delete tmp;
				//ɾ��pb�ڵ㣬���տռ�
				tmp = p2;
				p2 = p2->next;
				delete tmp;
			}
		}
		else if (p1->exponent>p2->exponent)//p1������p3����
		{
			Pnow->next = p1;
			Pnow = p1;
			p1 = p1->next;
		}
		else//p2������p3����
		{
			Pnow->next = p2;
			Pnow = p2;
			p2 = p2->next;
		}

	}//while
	
	Pnow->next = p1 ? p1 : p2;//����ǿն���ʽʣ��
	delete Pb;

	return OK;
}

Status PNode::OutPutPoly()
{
	if (!this&&!this->next)
	{
		std::cout << "Empty!\a" << std::endl;
		return ERROR;
	}
	PNode* p = this->next;
	while (p)
	{
		if (p == this->next) {
			if (p->exponent != 0)
				std::cout << p->coefficent << "x^" << p->exponent;
			else
				std::cout << p->coefficent;
		}
		else {
			if (p->coefficent > 0)std::cout << "+";
			if (p->exponent != 0)
				std::cout << p->coefficent << "x^" << p->exponent;
			else
				std::cout << p->coefficent;
		}
		p = p->next;
	}

	std::cout << std::endl;

	return OK;
}