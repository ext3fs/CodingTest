//programmers 42587
#include <iostream>
using namespace std;

class Node
{
	int n;		
public:
	Node(int arg) : n(arg) {
		cout << "create" << endl;
	}
	~Node(){
		cout << "delete" << endl;
	}
	Node(Node& src) : n(src.n) {
		cout << "copy create" << endl;
	}
	Node& operator=(const Node& rhs){
		cout << "copy = " << endl;
		n = rhs.n;
		return *this;
	}
	Node& operator=(const Node&& rhs){
		cout << "move = " << endl;
		n = rhs.n;
		return *this;
	}

	int print()
	{
		return n;
	}
};

Node fn(void)
{
	cout << "fn start" << endl;
	Node ret(2);
	cout << "fn end" << endl;
	return ret;
}

int main(void)
{
	Node a(1);
       	a = fn();
	
	cout << a.print() << endl;

	return	0;
}

