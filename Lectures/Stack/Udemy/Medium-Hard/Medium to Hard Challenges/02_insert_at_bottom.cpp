#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
	int size { };
	int top { };
	int* array { };
public:
	Stack(int size) :
			size(size), top(-1) {
		array = new int[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(int x) {
		assert(!isFull());
		array[++top] = x;
	}

	int pop() {
		assert(!isEmpty());
		return array[top--];
	}

	int peek() {
		assert(!isEmpty());
		return array[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
	}

	void insert_at_bottom(int x) {	// O(n) time & memory
		// Follow proper recursion tracing: What not How
		if (isEmpty())
			push(x);
		else {
			// Assume stack is [4, 3, 2, 1] and x = 10
			// let's pop the current element: 1
			int cur = pop();
			// Remaining is [4, 3, 2]
			// Now insert 10 at bottom
			// Now is: [10, 4, 3, 2]
			insert_at_bottom(x);
			// Push 1 again
			// Now is: [10, 4, 3, 2, 1]
			push(cur);
		}
	}
};

int main() {

	Stack stk(10);
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.display();	// 3 2 1
	stk.insert_at_bottom(7);
	stk.display();	// 3 2 1 7

	return 0;
}
