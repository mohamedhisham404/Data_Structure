#include <bits/stdc++.h>
using namespace std;

template<class T>class Stack{
private:
	int sz=100;
	vector<T>stack=vector<T>(sz);
	int top = -1;

public:
	void push(int value) {
	if (top == sz - 1)
		cout << "stack over flow";
	else {
		top++;
		stack[top] = value;
	}
	}
	T pop() {
		if (top == -1){
			cout << "stack is under flow";
			return 0;
		}
		else {
			return stack[top--];
		}
	}
	T peek() {
		if (top == -1){
			cout << "stack is under flow";
			return 0;
		}
		else {
			return stack[top];
		}
	}
	void display() {
		if (top == -1)
			cout << "stack is under flow";
		else {
			for (int i = top; i >= 0; i--)
				cout << stack[i] << endl;
		}
	}
};
int main() {
	Stack<int>st;
	st.push(5);
	st.push(10);
	st.push(15);
	st.display();
	cout << endl;
	st.pop();
	st.display();
	cout << endl;
	cout << "peek=" << st.peek();
	return 0;
}
