#pragma once

#include "Lista7.h"

template<class T>
class Nodo {
public:
	Nodo();
	~Nodo();
	Lista7<string>* getVecinos();
	int getContador();
	void setVecinos(Lista7<string>* vecinos);
	void setContador(int contador);
private:
	Lista7<T>* vecinos;
	int contador;
};

template<class T>
Nodo<T>::Nodo() :
	contador(0)
{
	vecinos = new Lista7<string>();
}

template<class T>
Nodo<T>::~Nodo()
{
}

template<class T>
Lista7<string>* Nodo<T>::getVecinos()
{
	return vecinos;
}

template<class T>
int Nodo<T>::getContador()
{
	return contador;
}

template<class T>
void Nodo<T>::setVecinos(Lista7<string>* vecinos)
{
	this->vecinos = vecinos;
}

template<class T>
void Nodo<T>::setContador(int contador)
{
	this->contador = contador;
}
