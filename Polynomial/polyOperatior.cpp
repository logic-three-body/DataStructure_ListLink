#include<iostream>
#include<string>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

//HELP：数据结构书P48
typedef struct PNode
{
private:
	float coefficent;
	int exponent;
public:
	PNode() :next(nullptr) {};//初始化不创建
	PNode(int num);//初始化并创建
	Status AddPoly( PNode*&Pb);//相加
	Status Minus(PNode*&Pb);//相减（取反相加）
	Status OutPutPoly();
	Status DerivPoly();
	Status MutiPoly(PNode*&Pb);
	Status MutiPolyFast(PNode*&Pb);
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
		if (choice == "-")
		{
			polyA->Minus(polyB);	
			polyA->OutPutPoly();
		}
		if (choice == "*")
		{
			polyA->MutiPolyFast(polyB);
		}
		if (choice == "'") {
			polyA->DerivPoly();
			polyB->DerivPoly();
			polyA->OutPutPoly();
			polyB->OutPutPoly();
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
		while (q&&q->exponent>s->exponent)//通过比较第一个大于输入项指数的项*q
		{
			pre = q;
			q = q->next;
		}
		//链接(pre->  -> s ->q)
		s->next = q;
		pre->next = s;

		//前插

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
	int sum = 0;//保留两系数和

	while (p1&&p2)
	{
		if (p1->exponent==p2->exponent)
		{
			sum = p1->coefficent + p2->coefficent;//保留系数和
			if (sum)
			{
				p1->coefficent = sum;//修改原链表此项(当前节点)系数
				Pnow->next = p1;
				Pnow = p1;
				p1 = p1->next;
				//删除pb节点，回收空间
				tmp = p2;
				p2 = p2->next;
				delete tmp;				
			}
			else
			{
				//删除this节点，回收空间
				tmp = p1;
				p1 = p1->next;
				delete tmp;
				//删除pb节点，回收空间
				tmp = p2;
				p2 = p2->next;
				delete tmp;
			}
		}
		else if (p1->exponent>p2->exponent)//p1链接在p3后面
		{
			Pnow->next = p1;
			Pnow = p1;
			p1 = p1->next;
		}
		else//p2链接在p3后面
		{
			Pnow->next = p2;
			Pnow = p2;
			p2 = p2->next;
		}

	}//while
	
	Pnow->next = p1 ? p1 : p2;//插入非空多项式剩余
	delete Pb;

	return OK;
}

Status PNode::Minus(PNode *& Pb)
{
	if (!Pb&&!Pb->next)
	{
		return ERROR;
	}
	Polynomial p = Pb->next;
	while (p)
	{
		p->coefficent *= -1;//取相反数
		p = p->next;
	}
	this->AddPoly(Pb);
	return OK;
}

Status PNode::OutPutPoly()
{
	if (!this->next)
	{
		std::cout << 0 << std::endl;
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

Status PNode::DerivPoly()
{
	PNode* p = this->next;
	if (!p)
	{
		return ERROR;
	}
	PNode* r = nullptr;
	while (p)
	{
		p->coefficent *= p->exponent;
		--p->exponent;
		if (p->exponent< 0) {
			r = p;
			p = p->next;
			delete r;
		}
		else {
			p = p->next;
		}
	}
	return OK;
}

Status PNode::MutiPoly(PNode *& Pb)
{
	if (!Pb->next)
	{
		return ERROR;
	}
	Polynomial p1 = this->next;
	Polynomial p2 = Pb->next;
	Polynomial L3 =new PNode;//目标多项式
	Polynomial tmp = new PNode;
	while (p1)
	{
		while (p2)
		{
			Polynomial t = new PNode;
			t->coefficent = p1->coefficent*p2->coefficent;
			t->exponent = p1->exponent+p2->exponent;
			tmp->next = t;
			L3->AddPoly(tmp);
			p2 = p2->next;
		}
		p2 = Pb->next;
		p1 = p1->next;
	}
	this->next = L3->next;
	//delete L3;
	return OK;
}

Status PNode::MutiPolyFast(PNode *& Pb)
{
	if (!Pb->next)
	{
		return ERROR;
	}
	Polynomial p1 = this->next;
	Polynomial p2 = Pb->next;
	Polynomial L3 = new PNode;//目标多项式
	Polynomial tmp = new PNode;
	while (p1)
	{
		while (p2)
		{
			/*
			Polynomial t = new PNode;
			t->coefficent = p1->coefficent*p2->coefficent;
			t->exponent = p1->exponent + p2->exponent;
			tmp->next = t;
			L3->AddPoly(tmp);
			p2 = p2->next;
			*/

			p1->coefficent *= p2->coefficent;
			p1->exponent += p2->coefficent;
			p2 = p2->next;

		}
		p2 = Pb->next;
		p1 = p1->next;
	}
	//this->next = L3->next;
	//delete L3;
	return OK;
}
