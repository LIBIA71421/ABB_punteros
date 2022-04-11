#pragma once

#include "Node.h"
using namespace std;

template <class T>
class ABB {
private:
	Node<T>* root;
public:
	ABB() {
		root = NULL;
	}

	Node<T>* getRoot() {
		return root;
	}

	void setRoot(T value) {
		root = new Node<T>(value);
	}

	bool insertar(T element, Node<T>*& root) {
		bool ans = false;
		if (root == NULL) {
			root = new Node<T>(element);
			ans = true;
		}
		else {
			if (element > root->getElement()) {
				insertar(element, root->getRight());
				ans = true;
			}
			if (element < root->getElement()) {
				insertar(element, root->getIzq());
				ans = true;
			}
		}
		return ans;
	}

	void protectedPush(T element) {
		insertar(element, root);
	}

	void inTraversal(Node<T>*& root) {
		if (root != NULL) {
			inTraversal(root->getIzq());
			cout << root->getElement() << endl;
			inTraversal(root->getRight());
		}

	}

	void inTraversal() {
		inTraversal(root);
	}


	T findLowest(Node<T>*& root) {
		T lowest = NULL;
		if (root->getElement() != NULL) {
			lowest = root->getElement();

			if (root->getLeft() != NULL) {
				lowest = root->getIzq()->getElement();
			}
			else {
				lowest = findLowest(root->getIzq());
			}
		}
		return lowest;
	}

	Node<T>*& findLowest(Node<T>*& root, int a) {
		Node<T>* lowest = NULL;
		if (root->getElement() != NULL) {
			lowest = root;
			if (root->getIzq() != NULL) {
				lowest = root->getIzq();
			}
			else {
				lowest = findLowest(root->getIzq(), a);
			}
		}
		return lowest;
	}

	T findGreatest(Node<T>*& root) {
		T greatest = NULL;
		if (root->getElement() != NULL) {
			greatest = root->getElement();
			if (root->getRight() != NULL) {
				greatest = root->getRight()->getElement();
			}
			else {
				greatest = findGreatest(root->getRight());
			}
		}
		return greatest;
	}



	int count(Node<T>*& root) {
		int ans = 0, ans2 = 0, ans1 = 0;

		if (root == NULL) {
			ans = 0;
		}
		else {
			ans1 = count(root->getIzq());
			ans2 = count(root->getRight());
			ans = ans1 + ans2 + 1;
		}
		return ans;
	}

	int getHeight(Node<T>*& root) {
		int ans, A1, A2;
		if (root == NULL) {
			ans = 0;
		}
		else {
			A1 = getHeight(root->getIzq());
			A2 = getHeight(root->getRight());
			if (A1 > A2) {
				ans = A1 + 1;
			}
			else {
				ans = A2 + 1;
			}
		}
		return ans;
	}


	int getLeafCount(Node<T>*& root)
	{
		int ans = 0;


		if (root == NULL) {
			ans = 0;
		}
		else

			if (root->getIzq() == NULL && root->getRight() == NULL) {
				ans = 1;
			}
			else {
				ans = getLeafCount(root->getIzq()) +
					getLeafCount(root->getRight());
			}
		return  ans;
	}

	Node<T>*& search(Node<T>*& root, T* value) {

		if (root == NULL || root->getElement() == value)
			return value;


		if (root->getElement() < value)
			return search(root->getRight(), value);


		return search(root->getleft(), value);
	}

	bool deleteNode2(T value, Node<T>*& root){
		bool ans;
		if (root == NULL) {
			ans = false;
		}
		else{
			if (root->getElement() == value) {
				if (root->getIzq() != NULL && root->getRight() != NULL) {
					delete root;
				}
				else {
					if (root->getRight() != NULL) {
						Node<T>* menor = findLowest(root->getRight());
						root = menor;
						deleteNode2(menor, root->getRight());
					}
					else {
						Node<T>* mayor = findGreatest(root->getIzq());
						root = mayor;
						deleteNode2(mayor, root->getIzq());
					}
				}
			}
			else {
				if (value > root->getElement()) {
					deleteNode2(value, root->getRight());
				}
				else {
					deleteNode2(value, root->getIzq());
				}

			}
		}
		return ans;
	}


	bool deleteNode(T value, Node<T>*& root) {
		bool ans = false;
		T greatest, lowest;

		if (root != NULL) {

			if (value < root->getElement()) {
				ans = deleteNode(value, root->getIzq());
			}
			if (value > root->getElement()) {
				ans = deleteNode(value, root->getRight());
			}

			if (value == root->getElement()) {
				if (root->getIzq() == NULL && root->getRight() == NULL) {
					delete root;
					root = NULL;
					ans = true;
				}
				else {
					if (root->getIzq() != NULL) {
						greatest = findGreatest(root->getIzq());
						root->setElement(greatest);
						ans = deleteNode(greatest, root->getIzq());
					}

					else if (root->getRight() != NULL) {
						lowest = findLowest(root->getRight());
						root->setElement(lowest);
						ans = deleteNode(lowest, root->getRight());
					}

				}
			}

		}

		return ans;
	}

	bool deleteNode(T elem) {
		bool ans = false;
		ans = deleteNode(elem, root);
		return ans;
	}


	Node<T>*& getNext(T elem, Node<T>*& root, bool& exists) {

		Node<T>* next = NULL;

		if (root == NULL) {
			exists = false;
		}
		else

		{
			if (elem == root->getElement()) {
				exists = true;

				if (root->getRight() != NULL) {
					next = findLowest(root->getRight(), 1);
				}
				else {
					next = NULL;
				}
			}
			if (elem < root->getElement())
			{
				next = getNext(elem, root->getIzq(), exists);
				if (next == NULL && exists == true) {
					next = root;
				}
			}
			if (elem > root->getElement())
			{
				next = getNext(elem, root->getRight(), exists);
			}

		}

		return next;
	}

	Node<T>*& getNext(T elem) {
		bool ex;
		return this->getNext(elem, root, ex);
	}

	void printGivenLevel(Node<T>*& root, int level)
	{
		if (root != NULL)
		{
			if (level == 1) {
				cout << root->getElement() << endl;;
			}
			else if (level > 1) {
				printGivenLevel(root->getIzq(), level - 1);
				printGivenLevel(root->getRight(), level - 1);

			}
		}
	}

	void printGivenLevel(int level) {
		printGivenLevel(root, level);
	}

};