#include "nodo.h"

nodo::nodo(int nuevo){
    id = nuevo;
    padre = NULL;
    hojaIzquierda = NULL;
    hojaDerecha = NULL;
}

//Setters
void nodo::setPadre(nodo *p){
    padre =p;
}

void nodo::setHojaIzquierda(nodo *hI){
    hojaIzquierda=hI;
}

void nodo::setHojaDerecha(nodo *hD){
    hojaDerecha=hD;
}

//Getters
nodo *nodo::getPadre(){
    return padre;
}

nodo *nodo::getHojaIzquierda(){
    return hojaIzquierda;
}

nodo *nodo::getHojaDerecha(){
    return hojaDerecha;
}


