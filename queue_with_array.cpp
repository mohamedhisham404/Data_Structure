#include <bits/stdc++.h>
using namespace std;

template<class T>class Queue{
public:
	int front = -1, rear = -1;
	int sz=100;
	vector<T>queue=vector<T>(sz);	

	void enqueue(T value) {
		if (rear == sz - 1)
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
	T peek() {
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
			for (int i = front; i <= rear; i++)
				cout << queue[i] << "\n";
		}
		else {
			cout << "is empty";
		}
	}

};



int main() {
	Queue<double>q;
	q.enqueue(1.1);
	q.enqueue(2.1);
	q.enqueue(1.3);
	q.enqueue(1.6);
	q.dequeue();

	cout<<q.peek()<<endl;

	q.display();
	

	return 0;
}
