#pragma once

#include "Node.h"
#include <fstream>
#define TAM 10000

template<class T>
class MB
{
private:
	Node<T> arr[TAM];
	int ultimo;
public:
	MB();
	~MB();

	void insertar(T elem);
	void recuperar_Abajo_Arriba(int posNodo);
	void recuperar_Arriba_Abajo(int posNodo);
	T eliminarMayor();
	void recorrer();
	T getMayor();
	T getMenor();
	int getTam();
};

template<class T>
MB<T>::MB()
{
	/*for (int i = 0; i < TAM; i++)
	{
		arr[i] = new Node;
	}*/
	ultimo = -1;
}

template<class T>
MB<T>::~MB()
{

}

template<class T>
void MB<T>::recuperar_Arriba_Abajo(int posNodo)
{
	int posMayor;
	if (arr[posNodo*2].getPresente() == true && arr[posNodo*(2+1)].getPresente() == true)
	{
		if (arr[posNodo*2].getElem() > arr[posNodo*(2+1)].getElem())
		{
			posMayor = posNodo * 2;
		}
		else
		{
			posMayor = posNodo * (2 + 1);
		}
		if (arr[posMayor].getElem() > arr[posNodo].getElem())
		{
			T aux = arr[posMayor].getElem();
			arr[posMayor].setDato(arr[posNodo].getElem());
			arr[posNodo].setDato(aux);
//			recuperar_Arriba_Abajo(posMayor);
			recuperar_Arriba_Abajo(arr[posNodo].getElem());
		}
	}
	if (arr[posNodo * 2].getPresente() == true)
	{
		if (arr[posNodo * 2].getElem() > arr[posNodo].getElem())
		{
			T aux = arr[posNodo].getElem();
			arr[posNodo].setDato(arr[posNodo*2].getElem());
			arr[posNodo*2].setDato(aux);
			recuperar_Arriba_Abajo(posNodo * 2);
		}
	}
}

template<class T>
void MB<T>::recuperar_Abajo_Arriba(int posNodo)
{
	if (posNodo != 1)
	{
		if (arr[posNodo].getElem() > arr[posNodo / 2].getElem())
		{
			T aux = arr[posNodo / 2].getElem();
			arr[posNodo / 2].setDato(arr[posNodo].getElem());
			arr[posNodo].setDato(aux);
			recuperar_Abajo_Arriba(posNodo / 2);
		}
	}
}

template<class T>
void MB<T>::insertar(T elem)
{
	if (ultimo == -1)
	{
		ultimo = 1;
		arr[ultimo].setDato(elem);
		arr[ultimo].Presente(true);
	}
	else
	{
		ultimo = ultimo + 1;
		arr[ultimo].setDato(elem);
		arr[ultimo].Presente(true);
		recuperar_Abajo_Arriba(ultimo);
	}
}


template<class T>
void MB<T>::recorrer()
{
	for (int i = 1; i <= ultimo; i++)
	{
		cout << arr[i].getElem() << endl;
	}
}

template<class T>
T MB<T>::eliminarMayor()
{
	T mayor;
	if (ultimo == -1)
	{
		mayor = NULL;
	}
	else
	{
		mayor = arr[1].getElem();
		arr[1].setDato(arr[ultimo].getElem());
		arr[ultimo].Presente(false);
		ultimo = ultimo - 1;
		recuperar_Arriba_Abajo(1);
	}
	return mayor;
}

template<class T>
T MB<T>::getMayor()
{
	return arr[1].getElem();
}

template<class T>
T MB<T>::getMenor()
{
	return arr[ultimo].getElem();
}

template<class T>
int MB<T>::getTam()
{
	return ultimo;
}

