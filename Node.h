#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
	Node<T>* hi;
	Node<T>* her;
	char letra;
	char fin;
	public:
	Node();
	~Node();

	char getLetra();
	char getFin();
	Node<T>*& getHi();
	Node<T>*& getHer();

	void setLetra(char letra);
	void setFin(char fin);
	void setHi(Node* hi);
	void setHer(Node* her);
};

template<class T>
Node<T>::Node()
{
	this->hi = NULL;
	this->her = NULL;
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
char Node<T>::getLetra() {
    return letra;
}

template<class T>
char Node<T>::getFin() {
    return fin;
}

template<class T>
Node<T>*& Node<T>::getHi() {
    return hi;
}

template<class T>
Node<T>*& Node<T>::getHer() {
    return her;
}

template<class T>
void Node<T>::setLetra(char le) {
    letra = le;
}

template<class T>
void Node<T>::setFin(char fi) {
    fin = fi;
}
template<class T>
void Node<T>::setHi(Node* h) {
	hi = h;
}
template<class T>
void Node<T>::setHer(Node* he) {
    her = he;
}