
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class S {
protected:
	
	
	
public:
	int a;
	S() {};
	S(int x) :a(x) {};
	~S() { cout << "----Deleting S "<<a<<"\n"; };
	virtual void testS() { cout << "---I am in S " << a << "\n"; };
};
class S1 :public S {
	
	public:
		S1(int x) { a = x; };
		~S1() { cout << "--Deleting S1 " << a << "\n";
		};
	void testS() { cout << "--I am in S1 " << a << "\n"; };
};
void a(vector<S*> &bb) {
	for (int i = 0; i < 10; i++) {
		bb[i] = new S(i);
	}
}
void a1(vector<S> &bb) {

	for (int i = 0; i < 10; i++) {
		bb[i] = S(i);
	}
}
void f1() {
	cout << "NEW RUN 1" << endl;
	{
		//vector<S*> bb(10);
		vector<S*> bb(10);
		a(bb);
		cout << "Done with A \n\n";
		//a1(bbb);
		//cout << "Done with B \n\n";
		for (auto i : bb) {
			i->testS();
		}
		for (auto i : bb) {
			delete i;
		}
		//for (auto i : bbb) {
		//	i.testS();
		//}
		cout << "Done printing \n";
	}
	cout << "Done." << endl;
}
void f2() {
	cout << "NEW RUN 2" << endl;
	{
		vector<S> bb(10);
		a1(bb);
		cout << "Done with A \n\n";
		for (auto i : bb) {
			i.testS();
		}
		//for (auto i : bb) {
		//	delete i;
	//	}
		//sort(bb.begin(), bb.end(),max);
		cout << "Done printing \n";
	}
	cout << "Done." << endl;
}

int main()
{	
	f1();
	f2();
	return 0;
}

