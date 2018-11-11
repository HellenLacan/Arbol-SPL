#include <iostream>
#include "arbolspl.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    ArbolSPL *miArbolSpl = new ArbolSPL();
   /* miArbolSpl->insertar(3, miArbolSpl->getRaiz());
    miArbolSpl->insertar(1, miArbolSpl->getRaiz());
    miArbolSpl->insertar(3, miArbolSpl->getRaiz());
    miArbolSpl->insertar(8, miArbolSpl->getRaiz());
    miArbolSpl->insertar(7, miArbolSpl->getRaiz());
    miArbolSpl->insertar(25, miArbolSpl->getRaiz());
    miArbolSpl->insertar(32, miArbolSpl->getRaiz());
    miArbolSpl->insertar(15, miArbolSpl->getRaiz());
    miArbolSpl->insertar(65, miArbolSpl->getRaiz());
    miArbolSpl->insertar(85, miArbolSpl->getRaiz());
    miArbolSpl->insertar(30, miArbolSpl->getRaiz());
    miArbolSpl->insertar(5, miArbolSpl->getRaiz());
    miArbolSpl->insertar(25, miArbolSpl->getRaiz());

    miArbolSpl->buscar(8, miArbolSpl->getRaiz());
    miArbolSpl->EliminarNodo(miArbolSpl->getRaiz(),32);
    miArbolSpl->EliminarNodo(miArbolSpl->getRaiz(),7);

    //miArbolSpl->EliminarNodo(miArbolSpl->getRaiz(),100);

    //miArbolSpl->graficar(miArbolSpl);
    //miArbolSpl->preOrden(miArbolSpl->getRaiz());*/


    int n, opcion;

       do
       {
           printf( "\n   1. Agregar", 163 );
           printf( "\n   2. Buscar", 163 );
           printf( "\n   3. Eliminar", 163 );
           printf( "\n   4. Salir." );
           printf( "\n\n   Introduzca opcion (1-4): ", 162 );

           scanf( "%d", &opcion );


           switch ( opcion )
           {
               case 1: printf( "\n   Introduzca un numero: ", 163 );
                       scanf( "%d", &n );
                       miArbolSpl->insertar(n, miArbolSpl->getRaiz());
                       break;

               case 2: printf( "\n   Introduzca un numero: ", 163 );
                       scanf( "%d", &n );
                       miArbolSpl->buscar(n, miArbolSpl->getRaiz());
                       break;

               case 3: printf( "\n   Introduzca un numero ", 163 );
                       scanf( "%d", &n );
                       miArbolSpl->EliminarNodo(miArbolSpl->getRaiz(),n);
            }

            /* Fin del anidamiento */

       } while ( opcion != 4 );





    return 0;
}

