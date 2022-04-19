#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
	T Dato;
	Node<T>* Izq;
	Node<T>* Der;
	int FACTOR;
public:
	Node(T dato);
	Node();
	~Node();
	Node<T>*& getIzquierda();
	Node<T>*& getDerecha();
	T getDato();
	int getFactor();
	void setFactor(int palabra);
	void setDato(T dato);
	void setIzquierda(Node<T>* newizquierda);
	void setDerecha(Node<T>* newderecha);
};

template<class T>
Node<T>::Node()
{
	this->Izq = NULL;
	this->Der = NULL;
	this->Dato = NULL;
	this->FACTOR = 0;
}

template<class T>
Node<T>::Node(T dato)
{
	this->Izq = NULL;
	this->Der = NULL;
	this->Dato = dato;
	this->FACTOR = 0;
}

template<class T>
Node<T>::~Node()
{

}

template<class T>
Node<T>*& Node<T>::getIzquierda()
{
	return Izq;
}

template<class T>
Node<T>*& Node<T>::getDerecha()
{
	return Der;
}

template<class T>
T Node<T>::getDato()
{
	return Dato;
}

template<class T>
int Node<T>::getFactor()
{
	return FACTOR;
}

template<class T>
void Node<T>::setFactor(int palabra)
{
	FACTOR = palabra;
}

template<class T>
void Node<T>::setDato(T dato)
{
	Dato = dato;
}

template<class T>
void Node<T>::setIzquierda(Node<T>* newizquierda)
{
	Izq = newizquierda;
}

template<class T>
void Node<T>::setDerecha(Node<T>* newderecha)
{
	Der = newderecha;
}

