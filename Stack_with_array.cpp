#include<iostream>
using namespace std;
#define size 5
int stack[size], top = -1;
void push(int value);
void display();
int peek();
int pop();

int main() {
	push(5);
	push(10);
	push(15);
	display();
	cout << endl;
	pop();
	display();
	cout << endl;
	cout << "peek=" << peek();
	return 0;
}
void push(int value) {
	if (top == size - 1)
		cout << "stack over flow";
	else {
		top++;
		stack[top] = value;
	}
}
int pop() {
	if (top == -1)
		cout << "stack is under flow";
	else {
		return stack[top--];
	}
}
int peek() {
	if (top == -1)
		cout << "stack is under flow";
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
