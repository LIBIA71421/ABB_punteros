// mincut.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Mincut.h"
#include <math.h>

int main()
{
    Mincut mincut;
    
    int min = 10000;
    double tam = mincut.getTamGrafo();
    int  res = 0;
    double n = 0;
    int resp= 0;
    
    mincut.llenarDesdeArchivo("MIN_CUT_CON_NOMBRES3.txt");
//    mincut.llenarDesdeArchivo("archivo.txt");
    mincut.mostrar();
    cout << "++++++++++++++++++" << endl;
    resp = mincut.algoritmo();
    cout << endl << " ++++++++++++++++++mostrar2" << endl;
    mincut.mostrar();
    cout << endl << " ++++++++++++++++++mostrar3" << endl;
    
    //cout << mincut2.getTamActual();
    cout << "CORTE MINIMO >> " << resp;

    

/*  
    
    while (n < (tam * tam) * log10(tam))
        {
            grafo = grafoOri;
            res = minCut(grafo);
            cout << res << endl;
            if (res < min)
            {
                min = res;
            }
            n++;
        }
    cout << "el minimo es: " << min << endl;
    return 0;



    Mincut mincut;
    mincut.llenarDesdeArchivo("MIN_CUT_CON_NOMBRES3.txt");
    int n = mincut.getTamGrafo();
    int logN = (int)log(n);
    int i = 0;
    int max = n * n * logN;
    int min = 100000;
    cout << max << endl;
    while (i < max)
    {
        Mincut mincut2 = mincut;
        cout << " tam: " << mincut2.getTamGrafo();
        int res = mincut2.algoritmo();
        cout << "res: " << res << endl;
        if (res < min) {
            cout << "hola" << endl;
            min = res;
        }
        cout << min << endl;
        i++;
    }*/
}

