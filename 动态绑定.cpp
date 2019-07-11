#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class B {
public:
	void print() { cout << "In the print of B!" << endl; }
	virtual void out() { cout << "In the out of B!" << endl; }
};
class C : public B {
public:
	void print() { cout << "In the print of C!" << endl; }
	virtual void out() { cout << "In the out of C!" << endl; }
};
class D : public B {
public:
	void print() { cout << "In the print of D!" << endl; }
	virtual void out() { cout << "In the out of D!" << endl; }
};

int main() {
	D* d = new D(); //静态类型是D*，动态类型也是D*
	B* b = d;		//静态类型是B*，动态类型是D*
	
	// 不是虚函数，所以是静态绑定
	d->print();		//d调用的是D.print()
	b->print();		//b调用的是B.print()

	// 虚函数是动态绑定
	d->out();		//d调用的是D.print()
	b->out();		//b调用的是D.print()
	return 0;
}
