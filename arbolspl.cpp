#include "arbolspl.h"

ArbolSPL::ArbolSPL(){
    raiz=NULL;
}

void ArbolSPL::setRaiz(nodo *r){
  raiz=r;
}

nodo* ArbolSPL::getRaiz(){
  return raiz;
}

void ArbolSPL::insertar(int id, nodo *raiz){
  nodo* nuevo = new nodo(id);

  if(raiz == NULL){
      setRaiz(nuevo);
  }else{
      if(raiz->id == nuevo->id){
          printf("NO se puede insertar");
          return;
      }else if(nuevo->id < raiz->id){
        if(raiz->getHojaIzquierda()==NULL){
            raiz->setHojaIzquierda(nuevo);
            //raiz->getHojaIzquierda()->setPadre(raiz);
        }else{
            insertar(id,raiz->getHojaIzquierda());
        }
      }else{
        if(raiz->getHojaDerecha() == NULL){
            raiz->setHojaDerecha(nuevo);
            //raiz->getHojaDerecha()->setPadre(raiz);
        }else{
            insertar(id,raiz->getHojaDerecha());
        }
      }
      setRaiz(balancear(getRaiz(),id));
  }
  graficar(this);
}

 nodo* ArbolSPL::RotacionIzquierda(nodo *pivote){
    nodo *aux = pivote->getHojaDerecha();
    pivote->setHojaDerecha(aux->getHojaIzquierda());
    aux->setHojaIzquierda(pivote);
    return aux;
}

 nodo* ArbolSPL::RotacionDerecha(nodo *pivote){
    nodo *aux = pivote->getHojaIzquierda();
    pivote->setHojaIzquierda(aux->getHojaDerecha());
    aux->setHojaDerecha(pivote);
    return aux;
}

 nodo* ArbolSPL::balancear(nodo *raiz, int id){
    if (raiz == NULL || raiz->id == id){
        return raiz;
    }

    if (raiz->id > id){
        if (raiz->getHojaIzquierda() == NULL){
            return raiz;
        }
        if (raiz->getHojaIzquierda()->id > id){// rotacion zig zig
            raiz->getHojaIzquierda()->setHojaIzquierda(balancear(raiz->getHojaIzquierda()->getHojaIzquierda(), id));
            raiz = RotacionDerecha(raiz);
        }else if (raiz->getHojaIzquierda()->id < id){ // Zig-Zag
            raiz->getHojaIzquierda()->setHojaDerecha(balancear(raiz->getHojaIzquierda()->getHojaDerecha(), id));
            if (raiz->getHojaIzquierda()->getHojaDerecha() != NULL)
                raiz->setHojaIzquierda(RotacionIzquierda(raiz->getHojaIzquierda()));
        }

        if(raiz->getHojaIzquierda() == NULL){
            return raiz;
        }else{
            return RotacionDerecha(raiz);
        }

    }else{
        if (raiz->getHojaDerecha() == NULL){
            return raiz;
        }
        if (raiz->getHojaDerecha()->id > id){ // rotacion zig-zag
            raiz->getHojaDerecha()->setHojaIzquierda(balancear(raiz->getHojaDerecha()->getHojaIzquierda(), id));
            if (raiz->getHojaDerecha()->getHojaIzquierda() != NULL)
                raiz->setHojaDerecha(RotacionDerecha(raiz->getHojaDerecha()));
        }else if (raiz->getHojaDerecha()->id < id){// rotacion zag-zag
            raiz->getHojaDerecha()->setHojaDerecha(balancear(raiz->getHojaDerecha()->getHojaDerecha(), id));
            raiz = RotacionIzquierda(raiz);
        }

        if(raiz->getHojaDerecha() == NULL){
            return raiz;
        }else{
            return RotacionIzquierda(raiz);
        }
        //return (raiz->getHojaDerecha() == NULL)? raiz: RotacionIzquierda(raiz);
    }
}

void ArbolSPL::graficar(ArbolSPL *arbol){
    nodo *auxiliar=arbol->raiz;
    FILE *archivo;;
    char direccion[]="/home/hellen/Escritorio/ARBOL.dot";

    archivo = fopen(direccion,"w");
    fprintf(archivo, "digraph G{\n");

    if(arbol->raiz != NULL){
        fprintf(archivo,"subgraph cluster1 {\nlabel=\"ABB ESTUDIANTES \";\ncolor=red;\n");
        graficarArbolSPL(auxiliar, archivo);
        fprintf(archivo,"}\n");
    }else{
        printf("El arbol se encuentra vacia");
    }

    fprintf(archivo,"}\n");
    fclose(archivo);

    system("dot -Tpng /home/hellen/Escritorio/ARBOL.dot -o ARBOL.png");
    system("cd /home/hellen");
    system("xdg-open ARBOL.png");
}

void ArbolSPL::graficarArbolSPL(nodo *pivote, FILE *archivo){
    if(pivote != NULL){
        fprintf(archivo,"nodo%u [label=\"%d\"];\n",
                pivote,pivote->id);

        graficarArbolSPL(pivote->getHojaIzquierda(),archivo);
        if(pivote->getHojaIzquierda() != NULL){
            fprintf(archivo, "nodo%u -> nodo%u [label=HI];\n",
                   pivote,pivote->getHojaIzquierda());
        }

        graficarArbolSPL(pivote->getHojaDerecha(),archivo);
        if(pivote->getHojaDerecha() != NULL){
            fprintf(archivo, "nodo%u -> nodo%u [label=HD];\n",
                    pivote,pivote->getHojaDerecha());
        }
    }else{
        return;
    }
}

void ArbolSPL::preOrden(nodo* raiz){
    if(raiz != NULL){
        printf("%d, ", raiz->id);
        preOrden(raiz->getHojaIzquierda());
        preOrden(raiz->getHojaDerecha());
    }
}

nodo* ArbolSPL::buscar(int id, nodo *raiz){
    setRaiz(balancear(getRaiz(), id));
    graficar(this);
}

void ArbolSPL:: EliminarNodo(nodo *Raiz, int Id){
    nodo *Actual;
    if (Raiz != NULL){
            setRaiz(balancear(getRaiz(), Id));
            //graficar(this);
            if (Id == getRaiz()->id){
                if (!getRaiz()->getHojaIzquierda()){
                    Actual = Raiz;
                    setRaiz(getRaiz()->getHojaDerecha());
                    //graficar(this);
                }else{
                    Actual = getRaiz();
                    setRaiz(balancear(getRaiz()->getHojaIzquierda(), Id));
                    //graficar(this);
                    getRaiz()->setHojaDerecha(Actual->getHojaDerecha());
                    graficar(this);
                }
            }else{
                printf("No existe el valor");
            }
    }
}

nodo* ArbolSPL::buscarNodo(int dato, nodo *auxiliar){
    if(auxiliar != NULL){
         if(dato < auxiliar->id ){
                buscar(dato,auxiliar->getHojaIzquierda());
         }else if(dato > auxiliar->id){
                buscar(dato,auxiliar->getHojaDerecha());
         }else {
                 return auxiliar;
         }
    }else {
        return NULL;
    }
}
