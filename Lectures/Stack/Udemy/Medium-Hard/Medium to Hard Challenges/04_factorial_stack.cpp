#include <iostream>
#include <cassert>
using namespace std;

struct StackElement {
	int n;
	int result { -1 };	// if < 0, not answered

	StackElement(int n = 1, int result = -1) :
			n(n), result(result) {
	}
	bool is_computed() {
		return result >= 0;
	}
};

class Stack {
private:
	int size { };
	int top { };
	StackElement* array { };	// only change
public:
	Stack(int size) :
			size(size), top(-1) {
		array = new StackElement[size] { };
	}

	~Stack() {
		delete[] array;
	}

	void push(StackElement x) {
		assert(!isFull());
		array[++top] = x;
	}

	StackElement pop() {
		assert(!isEmpty());
		return array[top--];
	}

	StackElement peek() {
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

int factorial(int n) {
	if (n <= 1)
		return 1;
	int subresult = factorial(n - 1);
	return n * subresult;
}

int factorial_stack(int n) {
	if (n <= 1)
		return 1;

	Stack st(n);
	st.push(StackElement(n));
	StackElement cur(1);

	// Simulate recursion
	// Every stack call get into stack
	// Once reaches base, stop and go back with result

	while (!st.isEmpty()) {
		cur = st.peek();

		if (!cur.is_computed()) {	// more recursive calls!
			if (cur.n <= 1) {		// base case: finally stop
				cur.result = 1;
				st.pop();
				st.push(cur);
			} else
				st.push(StackElement(cur.n - 1));	// factorial(cur-1);
		} else {
			// The previous element called me?
			cur = st.pop();
			if (!st.isEmpty()) {	// someone called me
				StackElement parent = st.pop();
				parent.result = parent.n * cur.result;	// n * fact(n-1)
				st.push(parent);
			}
		}
	}
	return cur.result;
}

int main() {
	for (int i = 0; i < 10; ++i) {
		cout << i<<" "<<factorial_stack(i) << "\n";
	}


	return 0;
}
