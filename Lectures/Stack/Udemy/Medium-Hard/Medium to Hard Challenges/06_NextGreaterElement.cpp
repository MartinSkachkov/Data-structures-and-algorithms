#include<iostream>
#include<cassert>
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
};

void next_greater_num(int v[], int len) {
	// Stack if all positions we are waiting for future answer for the,
	Stack pos(len);

	/*
	 * Reverse thinking
	 * 	Instead of finding the next greater of an element
	 * 	Use an element to find all items it is greater than them
	 *
	 * We will add each new element in the stack waiting for its next greater
	 *
	 * Given a new number, iterate on all previous in the stack
	 * 	and mark my self as their next great
	 * 	but stop once found a number >= me
	 * 	why? because I can't be used for more numbers (he is better than me)
	 *
	 * 	Example: {30, 20, 10, 7, 8, 15}
	 * 	Assume stack has now positions for { 30, 20, 10, 7}
	 * 	Now we have 8: 8 pops from stack 7 as it is > than it, but stop at 10
	 * 	Now we have 15: 15 pops from stack 8, 10 as it is > than it, but stop at 20
	 * 	and so on
	 *
	 * O(n) time! We iterate on numbers ~twice
	 */
	for (int i = 0; i < (int) len; ++i) {
		while (!pos.isEmpty() && v[i] > v[pos.peek()])
			v[pos.pop()] = v[i];
		pos.push(i);
	}
	// all items in the stack are not answered
	while (!pos.isEmpty())
		v[pos.pop()] = -1;

	for (int i = 0; i < (int) len; ++i)
		cout << v[i] << " ";
	cout<<"\n";

}

int main() {
	const int LEN1 = 8;
	int v1[LEN1] { 73, 74, 75, 71, 69, 72, 76, 73 };
	next_greater_num(v1, LEN1);

	const int LEN2 = 13;
	int v2[LEN2] { 20, 10, 7, 8, 9, 15, 14, 13, 12, 13, 14, 15, 16 };
	next_greater_num(v2, LEN2);

	return 0;
}
