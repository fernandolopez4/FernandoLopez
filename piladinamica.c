#include <stdio.h>
#include <stdlib.h>

typedef struct Tnodo *Pila;

struct Tnodo{
        int valor;
        Pila abajo;
}
main(){
Pila P;
crear(&P);
agregar(&P,5);
agregar(&P,3);
agregar(&P,2);
mostrar(P);
printf("\n%d\n",ver_tope(P));
eliminar_elemento(&P);
mostrar(P);
eliminar(&P);
printf("\n");
mostrar(P);
return ;
}

void crear(Pila *P){    ///crear pila vacia///
    (*P)=NULL;
}
void mostrar(Pila P){

        if(P == NULL)
            printf("No hay datos en la pila");
        else{
            printf("%i->",P->valor);
            mostrar(P->abajo);
        }

}
void eliminar(Pila *P){

        if((*P)==NULL)  ///si la pila esta vacia///
            return;
        else{
            Pila aux=(*P);
            (*P)=(*P)->abajo;  ///avanzamos hacia abajo///
             free(aux);        ///eliminamos el primer elemento///
             eliminar(P);
            }
}
void agregar(Pila *P, int val){    ///PUSH///

        if((*P)== NULL){            ///si la pila esta vacia///
           (*P)= malloc(sizeof(struct Tnodo));
           (*P)->valor = val;
           (*P)->abajo=NULL;
        }
        else{                       ///si la pila tiene algun elemento///
            Pila aux;
            aux = malloc(sizeof(struct Tnodo));
            aux->valor = val;
            aux->abajo = (*P);
            (*P) = aux;
        }
}
void eliminar_elemento(Pila *P){    ///POP///

            if((*P)==NULL){          ///si la pila esta vacia///
                printf("Pila vacia \n");
            }
            else{
                Pila aux = (*P);    ///si la pila tiene algun elemento///
                (*P)=(*P)->abajo;
                free(aux);
            }
}
int ver_tope(Pila P){
        return P -> valor;
}
