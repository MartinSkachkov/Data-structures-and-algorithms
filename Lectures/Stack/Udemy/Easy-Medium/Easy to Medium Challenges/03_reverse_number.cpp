#include <iostream>
#include <cassert>
using namespace std;

// simple trick to avoid re-changing the class
typedef int type;

class Stack {
private:
	int size { };
	int top { };
	type* array { };
public:
	Stack(int size) :
			size(size), top(-1) {
		array = new type[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(type x) {
		assert(!isFull());
		array[++top] = x;
	}

	type pop() {
		assert(!isEmpty());
		return array[top--];
	}

	type peek() {
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
};

int reverse_num(int num) {
	if (num == 0)
		return 0;

	Stack s(25);
	while (num)
		s.push(num % 10), num /= 10;

	int tens = 1;
	while(!s.isEmpty())
		num = s.pop() * tens + num, tens *= 10;

	return num;
}

int main() {
	cout<<reverse_num(123456)<<"\n";
	cout<<reverse_num(-123456)<<"\n";

	return 0;
}
