/* 
 *设计包含min函数的栈
 */

#include <iostream>

using namespace std;

#define MAXSIZE 1024

class Stack {
public:
	Stack();
	~Stack();
	void Push(int x);
	void Pop(int &x);
	void Min(int &m);
private:
	int *data;
	int *min;
	int top;
};

Stack::Stack()
{
	data = new int[MAXSIZE];
	min  = new int[MAXSIZE];
	top = -1;
}

Stack::~Stack()
{
	delete [] data;
	delete [] min;
}

void Stack::Push(int x)
{
	if (top+1 >= MAXSIZE){
		cout << "error:stack is full" << endl;
		return;
	}

	if (top == -1 || x < min[top]) 
		min[top+1] = x;
	else
		min[top+1] = min[top];

	data[++top] = x;
}

void Stack::Pop(int &x)
{
	if (top == -1) {
		cout << "error:stack is empty" << endl;
		return;
	}

	x = data[top--];
}

void Stack::Min(int &m)
{
	m = min[top];
}

int main()
{
	Stack *st = new Stack();

	int min,x;

	st->Push(2);
	st->Push(4);
	st->Push(3);
	st->Push(1);
	st->Min(min);
	cout << min << endl;
	st->Pop(x);
	st->Min(min);
	cout << min << endl;

	return 0;
}
