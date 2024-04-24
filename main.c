#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"

void cargaUsuario (Pila *p);
void pasaPila (Pila *p, Pila *q);
void ordenaPorSeleccion (Pila *p, Pila *q);
void muestraPila(Pila p);

int main()
{
    Pila usuario;
    Pila aux;
    Pila ordenada;
    inicpila(&usuario);
    inicpila(&aux);
    inicpila(&ordenada);
    int menor;

    cargaUsuario(&usuario);
    printf("Datos usuario:\n");
    muestraPila(usuario);

    pasaPilaOrdenando(&usuario, &aux);
    printf("Pila aux:\n");
    muestraPila(aux);

    menor = datoMenor(&aux);
    printf("El dato menor es: %d\n", menor);
    //Los datos estan en aux.
    ordenaPorSeleccion(&aux, &ordenada);
    printf("Pila ordenada: \n");
    muestraPila(ordenada);
    //Los datos estan en ordenada.

    return 0;
}
//1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
void cargaUsuario (Pila *p)
{
    char opcion;
    int datos;

    while(opcion != 27){
            printf("Ingrese datos: \n");
            scanf("%d", &datos);
            apilar(p, datos);

            printf("ESC para salir, cualquier tecla para continuar\n");
            opcion=getch();
            system("cls");
    }
}
 //Hacer una función que pase todos los elementos de una pila a otra.
 void pasaPila (Pila *p, Pila *q)
 {
     while(!pilavacia(p)){
        apilar(q, desapilar(p));
     }
 }
  //Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.
void pasaPilaOrdenando (Pila *p, Pila *q)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p)){
        apilar(&aux, desapilar(p));
    }
    while(!pilavacia(&aux)){
            apilar(q, desapilar(&aux));
    }
}
//4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.
int datoMenor (Pila *p)
{
    int menor;
    Pila aux;
    Pila menores;
    inicpila(&aux);
    inicpila(&menores);

        if (!pilavacia(p)){
            menor = desapilar(p);
        }
        while(!pilavacia(p)){
            if (tope(p) < menor){
                apilar(&aux, menor);
                menor = desapilar(p);
            }else {
                apilar(&aux, desapilar(p));
            }
        }
    pasaPila(&aux, p);

    return menor;
}
//5. Hacer una función que pase los elementos de una pila a otra,
// de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
void ordenaPorSeleccion (Pila *p, Pila *q)
{
    while(!pilavacia(p)){
            apilar(q, datoMenor(p));
    }
}
void muestraPila(Pila p)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    while(!pilavacia(&p)){
        apilar(&aux, desapilar(&p));
    }

    while(!pilavacia(&aux)){
        printf("%d | ",tope(&aux));
        apilar(&aux2, desapilar(&aux));
    }
}
//Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.

