#ifndef ARBOLSPL_H
#define ARBOLSPL_H
#include <string>
#include "nodo.h"

class ArbolSPL
{
public:
    nodo *raiz;

    ArbolSPL();

    // Metodos
    void setRaiz(nodo *n);
    nodo* getRaiz();
    void insertar(int, nodo*);
    void getEstudiante();
    void graficarArbolSPL(nodo*, FILE*);
    void graficar(ArbolSPL*);
    nodo* buscar(int, nodo*);
    void preOrden(nodo*);
    nodo* balancear(nodo*, int);
    nodo* RotacionIzquierda(nodo*);
    nodo* RotacionDerecha(nodo*);
    void EliminarNodo(nodo *Raiz, int Id);
    nodo* buscarNodo(int, nodo*);

};

#endif // ARBOLSPL_H
