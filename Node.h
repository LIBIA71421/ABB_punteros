#pragma once
#include <iostream>
#include "Lista7.h"

using namespace std;

template <class T>
class Node {
private:
	T element;
	Lista7<T>* lista7;
	bool marca;
	int padre;
public:
	Node() {
		marca = false;
		padre = -1;
		lista7 = new Lista7<T>();
	}
	T getElement() {
		return element;
	}
	void setElement(T newElement) {
		this->element = newElement;
	}
	void setMarca(bool marc) {
		marca = marc;
	}
	bool getMarca() {
		return marca;
	}
	void setPadre(int pad) {
		padre = pad;
	}
	int getPadre() {
		return padre;
	}
	Lista7<T>* getLista7() {
		return lista7;
	}

};
