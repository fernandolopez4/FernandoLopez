#include<stdio.h>
#include<stdlib.h>
#define max 4

typedef struct lista_array{
        int longitud;
        int ventana;
        int datos[max];
        }*Lista;

void main(){
    Lista L;
    L=inicLista();
    imprimirLista(L);
    anxLista (L,1);
    anxLista (L,2);
    anxLista (L,3);
    anxLista (L,4);
    imprimirLista(L);


}

void inicLista(){
        int i;
        Lista aux;
        aux = (Lista)malloc(sizeof(struct lista_array));
        aux->longitud = 0;
        aux->ventana = -1;
        i=0;
        while(i < max){
            aux -> datos[i]=0;
            i=i+1;
        }
return(aux);
}
void imprimirLista(Lista L){
        int i;
        i=0;
        printf("cantidad %i\n",L->longitud);
        printf("Ventana %i",L->ventana);
        while(i < L->longitud){
                printf("\n valor = %i\n",L->datos[i]);
                i= i + 1;

        }

}


void anxLista(Lista L,int elemento){
    int inicio;
    int fin;

    if(L->longitud == max-1){
        printf("lista llena");
    }
    else
    if(L->ventana != -1){
        fin = L->longitud;
        inicio= L->ventana + 1;
        while(fin>inicio){
            L-> datos[fin] = L-> datos[fin - 1];
            fin= fin -1 ;
        }

    }
    L-> ventana = L->ventana + 1;
    L-> datos[L->ventana]=elemento;
    L->longitud = L->longitud+1;

}
