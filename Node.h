#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
	T Dato;
	string Color;
	Node<T>* izquierda;
	Node<T>* derecha;
public:
	Node();
	~Node();
	Node<T>*& getIzquierda();
	Node<T>*& getDerecha();
	T getDato();
	string getColor();
	void setColor(string palabra);
	void setDato(T dato);
	void crearIzquierda(Node<T>* newizquierda);
	void crearDerecha(Node<T>* newderecha);
//	void operator=(T dato);
};

template<class T>
Node<T>::Node()
{
	this->izquierda = NULL;
	this->derecha = NULL;
	this->Dato = NULL;
	this->Color = "";
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
Node<T>*& Node<T>::getIzquierda()
{
	return izquierda;
}

template<class T>
Node<T>*& Node<T>::getDerecha()
{
	return derecha;
}

template<class T>
T Node<T>::getDato()
{
	return Dato;
}

template<class T>
string Node<T>::getColor()
{
	return Color;
}

template<class T>
void Node<T>::setColor(string palabra)
{
	Color = palabra;
}

template<class T>
void Node<T>::setDato(T dato)
{
	Dato = dato;
}

template<class T>
void Node<T>::crearIzquierda(Node<T>* newizquierda)
{
	izquierda = newizquierda;
}

template<class T>
void Node<T>::crearDerecha(Node<T>* newderecha)
{
	derecha = newderecha;
}
