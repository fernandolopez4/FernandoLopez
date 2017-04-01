#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int dato;
    struct Nodo *sgte;


}Nodo;

Nodo *primer = NULL;
Nodo *ultimo = NULL;

void agregar(Nodo *nodo){

    nodo -> sgte = NULL;

    if(primer == NULL){
        primer = nodo;
        ultimo = nodo;
    }
    else{
        ultimo -> sgte = nodo;
        ultimo = nodo;
    }
}

int main(){
    Nodo *primerNodo = malloc(sizeof(Nodo));
    primerNodo -> dato = NULL;

    Nodo *segundoNodo = malloc(sizeof(Nodo));
    segundoNodo -> dato = 23;

    agregar(primerNodo);
    agregar(segundoNodo);


    Nodo *i = primerNodo;
    while(i != NULL){
        printf("%i\n",i->dato);
        i = i->sgte;
    }

    return 0;
}
