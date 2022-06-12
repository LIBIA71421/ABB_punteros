#pragma once

#include "Nodo.h"
#include <map>
#include <set>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#define CLAVES_MAX 1000

typedef map<string, Nodo<string>> Grafo;
typedef Grafo::iterator GrafoIt;


class Mincut
{
public:
	Mincut();
	~Mincut();
	void llenarDesdeArchivo(string archivo);
	void mostrar();
	int algoritmo();
	void contraer(string vertice1, string vertice2);
	string obtenerVertice1();
	string obtenerVertice2(string vertice1);
	void eliminarTodo(string vertice);
	void eliminarAutoCiclos();
	int getTamGrafo();
	int getTamActual();
private:
	Grafo grafo;
	string claves[CLAVES_MAX];
	int clavesTamActual;
	int cont;
};

Mincut::Mincut() :
	clavesTamActual(0), cont(0)
{
	srand(time(NULL));
}

Mincut::~Mincut()
{
}

int Mincut::getTamGrafo()
{
	return grafo.size();
}

int Mincut::getTamActual() {
	return clavesTamActual;
}

int Mincut::algoritmo()
{
	int res = 0;
	while (grafo.size() > 2)
	{
		string vertice1 = obtenerVertice1();
		string vertice2 = obtenerVertice2(vertice1);
		//cout << "vertice1: " << vertice1 << endl;
		//cout << "vertice2: " << vertice2 << endl;
		contraer(vertice1, vertice2);
		res++;
		eliminarAutoCiclos();
	}
//	return res;
	GrafoIt it = grafo.begin();
//	return it->second.getContador();
	return	cont = it->second.getVecinos()->getTam();
}

void Mincut::eliminarAutoCiclos()
{
	for (GrafoIt it = grafo.begin(); it != grafo.end(); ++it)
	{
		while (it->second.getVecinos()->existe(new string(it->first)))
		{
			it->second.getVecinos()->eliminarElemDado(new string(it->first));
		}
	}
}

void Mincut::contraer(string vertice1, string vertice2)
{
	grafo[vertice2].getVecinos()->eliminarElemDado(new string(vertice1));
	grafo[vertice1].getVecinos()->eliminarElemDado(new string(vertice2));
	Par<string>* caminante = grafo[vertice2].getVecinos()->getPrimer();

	while (caminante != NULL)
	{
		grafo[vertice1].getVecinos()->insertarLista(caminante->getDato());
		grafo[*(caminante->getDato())].getVecinos()->eliminarElemDado(new string(vertice2));
		grafo[*(caminante->getDato())].getVecinos()->insertarLista(new string(vertice1));
		
		caminante = caminante->getSiguiente();
	}
	eliminarTodo(vertice2);
}

void Mincut::eliminarTodo(string vertice)
{
	grafo.erase(vertice);
	for (int i = 0; i < clavesTamActual; ++i)
	{
		if (claves[i] == vertice)
		{
			claves[i] = "vacio";
		}
	}
}

string Mincut::obtenerVertice1()
{
	int posV1 = 0;
	do {
		posV1 = rand() % clavesTamActual;
	} while (claves[posV1] == "vacio");
	return claves[posV1];
}

string Mincut::obtenerVertice2(string vertice1)
{
	GrafoIt it = grafo.find(vertice1);
	string v2;
	if (it != grafo.end())
	{
		int posV2 = rand() % it->second.getVecinos()->getTam();
		v2 = *it->second.getVecinos()->buscarIesimaPosicion(posV2);
	}
	return v2;
}

void Mincut::llenarDesdeArchivo(string archivo) {
	/*Grafo grafo2;
	for (GrafoIt it = grafo.begin(); it != grafo.end(); ++it) {
		grafo2.;
	}*/

	ifstream arch(archivo);
	string palabra;
	if (arch.fail()) {
		cout << "no se encontro el archivo....";
	}
	else {
		string verticeO;
		while (!arch.eof() && arch >> palabra)
		{
			if (palabra == "-1") {
				verticeO = "";
				continue;
			}
			if (verticeO.empty())
			{
				grafo.insert(make_pair(palabra, Nodo<string>()));
				verticeO = palabra;
				claves[clavesTamActual] = palabra;
				clavesTamActual++;
			}
			else
			{
				grafo[verticeO].getVecinos()->insertarLista(new string(palabra));
			}
		}
		arch.close();
	}
}


void Mincut::mostrar() {
	cout << "cantidad de vertices: " << grafo.size() << endl;
	for (GrafoIt it = grafo.begin(); it != grafo.end(); ++it) {
		cout << "Vertice origen: " << it->first << endl;
		cout << "\tAdyacente: ";
		it->second.getVecinos()->mostrar();
		cout << "-------------" << endl;
	}
}
