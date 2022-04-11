#pragma once
template <class T>
class Node {
private:
	T element;
	Node<T>* hijoIzq;
	Node<T>* hijoDer;

public:

	Node(T value) {

		hijoIzq = NULL;
		hijoDer = NULL;
		element = value;
	}

	void setIzq(Node<T>* left) {
		hijoIzq = left;
	}
	void setRight(Node<T>* right) {
		hijoDer = right;
	}
	void setElement(T newElement) {
		this->element = newElement;
	}
	Node<T>*& getIzq() {
		return hijoIzq;
	}
	Node<T>*& getRight() {
		return hijoDer;
	}
	T getElement() {
		return element;
	}


};