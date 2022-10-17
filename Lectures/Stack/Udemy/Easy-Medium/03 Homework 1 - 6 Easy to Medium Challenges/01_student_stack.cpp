#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
	int size { };
	int added_elements { };
	int* array { };
public:
	Stack(int size) :
			size(size) {
		array = new int[size];
	}

	~Stack() {
		delete[] array;
	}

	bool push(int x) {
		if (isFull())
			return false;

		for (int i = added_elements - 1; i >= 0; --i)
			array[i + 1] = array[i];
		array[0] = x;
		++added_elements;
		return true;
	}

	bool pop(int &result) {
		if (isEmpty())
			return false;
		result = array[0];
		for (int i = 0; i < added_elements - 1; ++i)
			array[i] = array[i + 1];
		--added_elements;
		return true;
	}

	bool peek(int &result) {
		if (isEmpty())
			return false;
		result = array[0];
		return true;
	}

	int isFull() {
		return added_elements == size;
	}

	int isEmpty() {
		return added_elements == 0;
	}

	void display() {
		for (int i = 0; i < added_elements; ++i)
			cout << array[i] << " ";
		cout << "\n";
	}
};

int main() {

	Stack stk(3);
	stk.push(10);
	stk.push(20);
	stk.push(30);

	if (!stk.push(50))
		cout << "Full Stack\n";

	stk.display();	// 30 20 10
	int result;
	if (stk.peek(result))
		cout << result << "\n";	// 30

	while (stk.pop(result)) {
		cout << result << " ";
	} // 30 20 10

	return 0;
}
