#include <iostream>
#include <fstream>
#include <string>
#include "ABB.h"
using namespace std;

int main() {
	ifstream arch("cien.txt");
	string palabra;

	ABB<string>* abb = new ABB<string>();

	if (arch.fail()) {
		cout << "no se encontro el archivo....";
		cin >> palabra;
	}
	else {
		while (!arch.eof())
		{
			arch >> palabra;
			abb->protectedPush(palabra);
		}
		arch.close();
	}

	Node<string>* root = abb->getRoot();
	cout << "There are: " << endl << abb->count(root) << " nodes" << endl;
	cin >> palabra;
	// Node<string>* root = abb->getRoot();
   //  abb->inTraversal(root);
	return 0;
}