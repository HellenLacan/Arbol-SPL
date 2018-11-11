#ifndef NODO_H
#define NODO_H
#include <string>

class nodo
{
public:
    int id;
    nodo *hojaIzquierda;
    nodo *hojaDerecha;
    nodo *padre;
    nodo(int);

    //Getters && Setters
    void setPadre(nodo *padre);
    void setHojaIzquierda(nodo *hojaDerecha);
    void setHojaDerecha(nodo *hojaIzquierda);

    nodo *getPadre();
    nodo *getHojaIzquierda();
    nodo *getHojaDerecha();
};

#endif // NODO_H
