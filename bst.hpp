#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class BST
{
private:
	struct Node
	{
		T data;

		Node* left;
		Node* right;

		Node(const T& data) : data(data), left(nullptr), right(nullptr)
		{}
	};

	Node* root;

public:
	BST();

	BST(const vector<T>& v);
	BST(const BST<T>& other);
	BST<T>& operator=(const BST<T>& other);
	~BST();

private:
	void copyFromRec(Node*& root, Node* otherRoot);
	void freeRec(Node* root);

	void copyFrom(const BST<T>& other);
	void free();

	void createBSTRec(Node*& root, const vector<T>& v, int start, int end);

	void findMax(Node* root, Node*& maxNode);

	bool containsRec(const T& el, Node* root, Node*& prev);
	void removeRec(const T& el, Node*& root);

	void printRec(Node* root, int space) const;

public:
	bool contains(const T& el) const;
	void insert(const T& el);
	void remove(const T& el);

	void print() const;
};





template <typename T>
BST<T>::BST(const vector<T>& v)
{
	if (!is_sorted(v.begin(), v.end()))
		throw "Array should be sorted!";

	createBSTRec(root, v, 0, v.size() - 1);
}




template <typename T>
void BST<T>::createBSTRec(Node*& root, const vector<T>& v, int start, int end)
{
	if (start > end)
	{
		root = nullptr;
		return;
	}

	int mid = start + (end - start) / 2;
	root = new Node(v[mid]);

	createBSTRec(root->left, v, start, mid - 1);
	createBSTRec(root->right, v, mid + 1, end);
}



template <typename T>
void BST<T>::printRec(Node* root, int space) const
{
	if (!root)
		return;

	int count = 10;

	space += count;
	printRec(root->right, space);

	cout << endl;
	for (int i = count; i < space; i++)
		cout << ' ';
	cout << root->data << endl;

	printRec(root->left, space);
}
template <typename T>
void BST<T>::print() const
{
	printRec(root, 0);
}