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

	void display_reversed() {
		for (int i = 0; i <= top; i++)
			cout << array[i] << " ";
		cout << "\n";
	}
};

void asteroidCollision(int arr[], int len) {
    Stack result(len);

    for (int i = 0; i < len; ++i) {
    	int asteroid = arr[i];
    	// For every new asteroid, remove all what will explode
    	// Only may happens when asteroid going backword and something coming forward
    		// asteroid < 0 && 0 < result.peek()
        bool is_exploded = false;
        while (!result.isEmpty() && asteroid < 0 && 0 <= result.peek()) {
        	// last will explode.
            if (result.peek() < -asteroid) {
                result.pop();
                continue;	// See if more explode
            } else if (result.peek() == -asteroid)	// both exploded
                result.pop();
            is_exploded = true;		// only asteroid explode
            break;
        }
        if (!is_exploded)
            result.push(asteroid);
    }
    result.display_reversed();
}

int main() {
	int arr[4] {10, 5, -2};
	asteroidCollision(arr, 3);

	// Try also 1, 0, -1, 1  ==> 1

	return 0;
}
