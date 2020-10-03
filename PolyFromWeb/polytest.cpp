#include<iostream>
#include<string>
using namespace std;
typedef struct PNode
{
	double coefficient;
	int exponent;
	struct PNode* next;
}*Polynomial;
void CreatePoly(Polynomial& L, int n)
{
	L = new PNode;
	L->next = nullptr;
	for (int i = 0; i < n; i++) {
		PNode* s = new PNode;
		cin >> s->coefficient >> s->exponent;
		PNode* pre = L;
		PNode* cur = L->next;
		while (cur && s->exponent < cur->exponent)
		{
			pre = cur;
			cur = cur->next;
		}
		s->next = cur;
		pre->next = s;
	}//按指数从大到小存多项式
}
void OutputPolynomial(Polynomial L)
{
	if (!L || !L->next) {
		cout << 0 << endl;
		return;
	}
	PNode* p = L->next;
	while (p)
	{
		if (p == L->next) {
			if (p->exponent != 0)
				cout << p->coefficient << "x^" << p->exponent;
			else
				cout << p->coefficient;
		}
		else {
			if (p->coefficient > 0)cout << "+";
			if (p->exponent != 0)
				cout << p->coefficient << "x^" << p->exponent;
			else
				cout << p->coefficient;
		}
		p = p->next;
	}
	cout << endl;
}
Polynomial PolyAdd(Polynomial L1, Polynomial L2)
{
	PNode* p1 = L1->next;
	PNode* p2 = L2->next;
	PNode* r = nullptr;
	Polynomial L3;
	CreatePoly(L3, 0);
	PNode* p3 = L3;
	while (p1 && p2)
	{
		if (p1->exponent == p2->exponent) {
			int sum = p1->coefficient + p2->coefficient;
			if (sum) {
				p1->coefficient = sum;
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
				p2 = p2->next;
			}
			else {
				p1 = p1->next;
				p2 = p2->next;
			}

		}
		else if (p1->exponent > p2->exponent) {
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else {
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}

	}
	p3->next = p1 ? p1 : p2;
	return L3;

}
void PolyMinus(Polynomial L1, Polynomial L2)
{
	PNode* p = L2->next;
	while (p)
	{
		p->coefficient *= -1;//取相反数
		p = p->next;
	}
	OutputPolynomial(PolyAdd(L1, L2));
}

void PolyMulti(Polynomial L1, Polynomial L2)
{
	PNode* p1 = L1->next;
	PNode* p2 = L2->next;
	Polynomial L3;//目标多项式
	CreatePoly(L3, 0);
	Polynomial temp;//记中间结果
	CreatePoly(temp, 0);
	while (p1)
	{
		while (p2)
		{
			PNode* t = new PNode;
			t->next = nullptr;
			t->coefficient = p1->coefficient * p2->coefficient;
			t->exponent = p1->exponent + p2->exponent;
			temp->next = t;
			L3 = PolyAdd(L3, temp);
			p2 = p2->next;
		}
		p2 = L2->next;
		p1 = p1->next;
	}
	OutputPolynomial(L3);
}
void PolyDervived(Polynomial L)
{
	PNode* p = L->next;
	PNode* r = nullptr;
	while (p)
	{
		p->coefficient *= p->exponent;
		p->exponent--;
		if (p->exponent < 0) {
			r = p;
			p = p->next;
			delete r;
		}
		else {
			p = p->next;
		}
	}
	OutputPolynomial(L);
}

int main()
{
	int times; cin >> times;
	while (times--)
	{
		int terms1, terms2;
		cin >> terms1 >> terms2;
		Polynomial L1, L2;
		CreatePoly(L1, terms1);
		CreatePoly(L2, terms2);
		string choice; cin >> choice;
		if (choice == "+")
		{
			OutputPolynomial(PolyAdd(L1, L2));
		}
		if (choice == "-")
		{
			PolyMinus(L1, L2);
		}
		if (choice == "*")
		{
			PolyMulti(L1, L2);
		}
		if (choice == "'") {
			PolyDervived(L1);
			PolyDervived(L2);
		}
	}
	return 0;
}