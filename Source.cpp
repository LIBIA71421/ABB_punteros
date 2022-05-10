#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
using namespace std;

int main() {
	ifstream arch("cien.txt");
	string palabra;

	Grafo<string>* g = new Grafo<string>();
	g->insertar(0, new string(""));









	/*
	if (arch.fail()) {
		cout << "no se encontro el archivo....";
		cin >> palabra;
	}
	else {
		while (!arch.eof())
		{
			arch >> palabra;
			//g->insertar(palabra,palabra);
		}
		arch.close();
	}*/

	

	return 0;
}