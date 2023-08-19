#include<iostream>
using namespace std;
#define size 5
int queue[size], front = -1, rear = -1;

void enqueue(int value);
void dequeue();
int peek();
void display();

int main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	display();
	cout << endl;
	dequeue();
	display();
	cout << endl;
	cout << "peek=" << peek();
}
void enqueue(int value) {
	if (rear == size - 1)
		cout << "queue is over flow";
	else if (front == -1 && rear == -1) {
		rear++;
		front++;
		queue[rear] = value;
	}
	else
		queue[++rear] = value;
}
void dequeue() {
	if (front != -1 && rear != -1 && front <= rear) {
		front++;
	}
	else {
		cout << "is empty";
	}
}
int peek() {
	if (front != -1 && rear != -1 && front <= rear) {
		return queue[front];
	}
	else {
		cout << "is empty";
		return -1;
	}
}
void display() {
	if (front != -1 && rear != -1 && front <= rear) {
		for (int i = front; i < rear; i++)
			cout << queue[i] << "\t";
	}
	else {
		cout << "is empty";
	}
}
