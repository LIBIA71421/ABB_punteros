#pragma once
#include <iostream>
#include "Lista7.h"
using namespace std;

template <class T>
class Cola
{
private:
    Lista7<T> L;
public:
    void poner(T val) {
        L.insertarFinal(val);
    }
    int sacar() {
        return L.eliminar_prin();
    }
    void mostrar() {
        L.mostrar();
    }
    Lista7<T> getLista() {
        return L;
    }
};
