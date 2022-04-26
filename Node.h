#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
	T Dato;
	bool presente;
	Node<T>* izquierda;
	Node<T>* derecha;
public:
	Node();
	~Node();
	T getElem();
	void Presente(bool palabra);
	bool getPresente();
	void setDato(T dato);
};

template<class T>
Node<T>::Node()
{
	this->izquierda = NULL;
	this->derecha = NULL;
	this->Dato = NULL;
	this->presente = false;
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
T Node<T>::getElem()
{
	return Dato;
}

template<class T>
void Node<T>::Presente(bool palabra)
{
	presente = palabra;
}

template<class T>
bool Node<T>::getPresente()
{
	return presente;
}

template<class T>
void Node<T>::setDato(T dato)
{
	Dato = dato;
}

