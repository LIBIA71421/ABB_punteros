#pragma once
#include <string.h>
#include "Node.h"

template <class T>
class ArbolTRIE
{
private:
	Node<T>* R;
public:
	ArbolTRIE();
	~ArbolTRIE();
	void Insertar(T elemento);
	void InsertarTRIE(Node<T>*& R, T elem, int pos);

	void mostrarInOrder();
	void mostrarInOrder(Node<T>* A);

	void SetRaiz(string color);
	void SetRaiz(Node<T>* A, string color);

	bool search(Node<T>*& root, T* value);
};

template<class T>
ArbolTRIE<T>::ArbolTRIE()
{
	R = NULL;
}

template<class T>
ArbolTRIE<T>::~ArbolTRIE()
{

}

template<class T>
void ArbolTRIE<T>::Insertar(T elem)
{
	int pos = 0;
	InsertarTRIE(R, elem, pos);
}

template<class T>
void ArbolTRIE<T>::InsertarTRIE(Node<T>*& R, T palabra, int pos)
{
	if (R == NULL)
	{
		R = new Node<T>();
		R->setLetra(palabra[pos]);
		if (pos == palabra.length()) {
			R->setFin('#');
		}
		else {
			InsertarTRIE(R->getHi(), palabra, pos++);
		}
	}
	else
	{
		if (R->getLetra() == palabra[pos])
		{
			InsertarTRIE(R->getHi(), palabra, pos++);
		}else{
			InsertarTRIE(R->getHer(), palabra, pos);
		}
	}
}
template<class T>
void ArbolTRIE<T>::SetRaiz(string color) {
	SetRaiz(R, color);
}

template<class T>
void ArbolTRIE<T>::SetRaiz(Node<T>* A, string color) {
	A->setColor(color);
}

template<class T>
void ArbolTRIE<T>::mostrarInOrder()
{
	mostrarInOrder(R);
	cout << endl;
}

template<class T>
void ArbolTRIE<T>::mostrarInOrder(Node<T>* R)
{
	if (R == NULL)
	{
		return;
	}
	else
	{
		mostrarInOrder(R->getHi());
		cout << R->getLetra() << ", " << R->getFin() << endl;
		mostrarInOrder(R->getHer());
	}
}
template<class T>
bool ArbolTRIE<T>::search(Node<T>*& R, T* value) {
	for (int i = 0; i < value.length(); i++)
	{
		char c = value.setLetra(i);
		sub = new Node<T>(); 
		sub = R->setHi(c);
		if (sub == null) return false;
	}
	return R.ends;
}

