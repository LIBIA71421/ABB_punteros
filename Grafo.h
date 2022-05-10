#pragma once
#include <iostream>
#include "Node.h"
#include "Cola.h"

template <class T>
class Grafo {
private:
    Node<T> arr[100];
    Cola<T> cola;
public:
    Grafo() {
      
    }
    void insertar(int v1, T* v2) {
        arr[v1].getLista7()->insertarLista(v2);
    }

    void mostrar() {
        for (int i = 0; i < 5; i++) {
            cout << i << ": " << " " << arr[i].getPadre() << "  " << arr[i].getMarca() << " --> ";
            arr[i].getLista7()->mostrar();
            cout << endl;
        }
    }
    bool BFS(int origen, int destino) {
        bool encontre = false;
        arr[origen]->setMarca();
        cola.poner(origen);
        int adya, vert, i_esimo;
        while (cola.getLista().getPrimer() != NULL and encontre == false) {
            i_esimo = 1;
            vert = cola.sacar();
            adya = arr[vert]->getLista7()->buscarIesimaPosicion(i_esimo);
            while (adya != -1 and encontre == false) {
                if (arr[adya]->getMarca() == false) {
                    arr[adya]->setPadre(vert);
                    if (adya == destino) {
                        arr[destino]->setMarca();//
                        encontre = true;
                    }
                    else {
                        arr[adya]->setMarca();//
                        cola.poner(adya);
                    }
                }
                i_esimo++;
                adya = arr[vert]->getLista7()->buscarIesimaPosicion(i_esimo);
            }
        }
        return encontre;
    }
    bool DFS(int origen, int destino) {
        bool encontre_camino = false;
        arr[origen]->setMarca();
        int i_esimo = 1;
        int adya = arr[origen]->getLista7()->buscarIesimaPosicion(i_esimo);
        while (adya != -1) {
            if (encontre_camino == false && arr[adya]->getMarca() == false) {
                arr[adya]->setPadre(origen);
                if (adya == destino) {
                    arr[destino]->setMarca();//
                    encontre_camino = true;
                }
                else {
                    encontre_camino = DFS(adya, destino);
                }
            }
            i_esimo++;
            adya = arr[origen]->getLista7()->buscarIesimaPosicion(i_esimo);
        }
        return encontre_camino;
    }
    void recorrerPadre(int destino) {
        int camino = destino;
        while (camino != -1) {
            cout << camino << " - ";
            camino = arr[camino]->getPadre();
        }
    }
};