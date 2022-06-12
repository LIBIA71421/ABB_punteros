#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Par.h"
#include "ListaVaciaException.h"

template<class T>
class Lista7
{
private:
	Par<T>* primer;
	Par<T>* ultimo;
public:
	Lista7();
	~Lista7();
	void leerArchivo(string nombreArchivo);
	void leerArchivo(string nombreArchivo, T* (*convertir)(string linea));
	void insertarPrincipio(T* dato);
	void eliminarPrincipio();
	void insertarLista(T* dato);
	void eliminarFinal();
	void mostrar(void (*mostrarT)(T*));
	void mostrar();
	T* buscarIesimaPosicion(int pos);
	Par<T>* getPrimer();
	void eliminarElemDado(T* dato);
	int getTam();
	bool existe(T* dato);
};

template<class T>
Lista7<T>::Lista7()
{
	primer = NULL;
	ultimo = NULL;
}

template<class T>
Lista7<T>::~Lista7()
{
	Par<T>* segundo;
	while (primer != NULL)
	{
		if (primer == ultimo)
		{
			delete primer;
			ultimo = NULL;
			primer = NULL;
		}
		else
		{
			segundo = primer->getSiguiente();
			delete primer;
			primer = segundo;
		}
	}
}

template<class T>
void Lista7<T>::leerArchivo(string nombreArchivo) {
	fstream archivo;
	archivo.open(nombreArchivo, ios::in);
	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea))
		{
			cout << linea << endl;
		}
		archivo.close();
	}
	else {
		cout << "no se encontro el archivo....";
	}
}

template<class T>
void Lista7<T>::leerArchivo(string nombreArchivo, T* (*convertir)(string linea)) {
	fstream archivo;
	archivo.open(nombreArchivo, ios::in);
	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea))
		{
			insertarLista(convertir(linea));
		}
		archivo.close();
	}
	else {
		cout << "no se encontro el archivo....";
	}
}

template<class T>
void Lista7<T>::insertarPrincipio(T* dato)
{
	if (primer == NULL)
	{
		primer = new Par<T>(dato, NULL);
		ultimo = primer;
	}
	else
	{
		Par<T>* aux = new Par<T>(dato, primer);
		primer = aux;
	}
}

template<class T>
void Lista7<T>::eliminarPrincipio()
{
	if (primer == NULL)
	{
		throw ListaVaciaException();
	}
	else if (primer == ultimo)
	{
		delete primer;
		primer = NULL;
		ultimo = NULL;
	}
	else
	{
		Par<T>* aux;
		aux = primer->getSiguiente();
		delete primer;
		primer = aux;
	}
}

template<class T>
void Lista7<T>::insertarLista(T* dato)
{

	if (primer == NULL && ultimo == NULL)
	{
		primer = new Par<T>(dato, NULL);
		ultimo = primer;
	}
	else
	{
		Par<T>* aux = ultimo;
		ultimo = new Par<T>(dato, NULL);
		aux->setSiguiente(ultimo);
	}
}
template<class T>
void Lista7<T>::eliminarFinal()
{
	if (primer == NULL)
	{
		throw ListaVaciaException();
	}
	if (primer == ultimo)
	{
		delete primer;
		ultimo = NULL;
		primer = NULL;
	}
	else
	{
		Par<T>* aux = primer;
		while (aux->getSiguiente() != NULL && aux->getSiguiente() != ultimo) {

			aux = aux->getSiguiente();
		}
		delete ultimo;
		ultimo = aux;
		ultimo->setSiguiente(NULL);
	}
}


template<class T>
void Lista7<T>::mostrar(void (*mostrarT)(T*))
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	else
	{
		Par<T>* aux = primer;
		while (aux != NULL)
		{
			(*mostrarT)(aux->getDato());
			aux = aux->getSiguiente();
		}
	}
}
template<class T>
void Lista7<T>::mostrar() {
	if (primer == NULL) {
		cout << " - ";
	}
	else {
		Par<T>* aux = primer;
		while (aux != NULL) {
			aux->mostrar();
			///cout << aux->getDato() << " - ";

			if (aux->getSiguiente())
				cout << " - ";
			aux = aux->getSiguiente();
		}
		cout << endl;
	}
}
template<class T>
T* Lista7<T>::buscarIesimaPosicion(int pos)
{
	Par<T>* aux = primer;
	T* datoEncontrado = NULL;
	int cont = 0;
	while (aux != NULL)
	{
		if (pos == cont)
		{
			datoEncontrado = aux->getDato();
		}
		cont++;
		aux = aux->getSiguiente();
	}
	return datoEncontrado;
}


template<class T>
Par<T>* Lista7<T>::getPrimer()
{
	return primer;
}

template<class T>

bool Lista7<T>::existe(T* dato) {
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	else
	{
		Par<T>* aux = primer;
		while (aux != NULL) {
			if (*aux->getDato() == *dato)
			{
				return true;
			}
			aux = aux->getSiguiente();
		}
	}
	return false;
}

template<class T>
void Lista7<T>::eliminarElemDado(T* dato) {
	if (primer == NULL && ultimo == NULL) {
		throw ListaVaciaException();
	}
	else {
		if (*dato == *primer->getDato()) {
			eliminarPrincipio();
		}
		else if (*dato == *ultimo->getDato()) {
			eliminarFinal();
		}
		else {
			Par<T>* aux = primer;
			while (*aux->getSiguiente()->getDato() != *dato && aux != NULL) {
				aux = aux->getSiguiente();
			}
			if (*aux->getSiguiente()->getDato() == *dato) {
				Par<T>* ayuda = aux->getSiguiente()->getSiguiente();
				delete aux->getSiguiente();
				aux->setSiguiente(ayuda);
			}
		}
	}
}

template<class T>
int Lista7<T>::getTam() {
	int tam = 0;
	if (primer == NULL) {
		return tam;
	}
	else {
		Par<T>* aux = primer;
		while (aux != NULL) {
			tam++;
			aux = aux->getSiguiente();
		}
	}
	return tam;
}
