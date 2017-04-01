#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	int inf;
	struct Nodo *anterior,*siguiente;
}pNodo;

typedef struct Lista
{
	int longitud;
	pNodo *primero,*ventana,*ultimo;
}pLista;

pLista *Iniclista()
{
	pLista *L;
	L =malloc(sizeof(pLista));
	L->longitud = 0;
	L->primero = L->ventana = L->ultimo = NULL;
	return (L);
}


int AgregarInicio(pLista *L, int numero)
{
	pNodo *nuevo;
	nuevo=malloc(sizeof(pNodo)); /*Pedir memoria*/
	nuevo->inf = numero;
	nuevo->anterior = nuevo->siguiente = NULL;
	L->ventana=L->primero;
	if(L->longitud==0)
	{
		L->ventana=L->ultimo=L->primero=nuevo;
	}
	else
	{
		nuevo->siguiente=L->ventana;
		L->ventana->anterior=nuevo;
		L->primero = nuevo;
	}	
	L->ventana=nuevo;
	L->longitud++;
	
}

int AgregaFinal(pLista *L, int numero)
{
	pNodo *nuevo;
	nuevo=malloc(sizeof(pNodo)); /*Pedir memoria*/
	nuevo->inf = numero;
	nuevo->anterior = nuevo->siguiente = NULL;	
	L->ventana=L->ultimo;
	if(L->longitud==0)
	{
		L->ventana=L->ultimo=L->primero=nuevo;
	}
	else
	{
		L->ventana->siguiente=L->ultimo=nuevo;
		nuevo->anterior=L->ventana;
	}
	L->ventana=nuevo;
	L->longitud++;
}


int EliminaUltimo(pLista *L)
{
	pNodo *nuevo;
	nuevo=L->ventana;
	L->ventana=L->ultimo;
	if(L->longitud == 0){printf("Error no hay lista");}
	else
	{
		if (L->longitud==1)
		{
			L->primero=L->ventana=L->ultimo=NULL;
		}
		else	
		{
		//	L->ventana->anterior->siguiente=NULL;
			L->ultimo=L->ventana->anterior;
			L->ventana=L->ventana->anterior;
			
		}	
		free(nuevo);
		L->longitud--;
	}
}

void EliminaPrincipio(pLista *L)
{
	pNodo *nuevo;
	nuevo=L->ventana;
	L->ventana=L->primero;
	if(L->longitud == 0){printf("Error no hay lista");}
	else
	{
		if (L->longitud==1)
		{
			L->primero=L->ventana=L->ultimo=NULL;
		}
		else	
		{
			L->ventana=L->primero;
			L->ventana=L->ventana->siguiente;
			L->primero=L->ventana;
		}	
		free(nuevo);
		L->longitud--;
	}
}

/*----------------------------------------------Main---------------------------------------------------------*/
int main()
{
	pLista *L=Iniclista();
	AgregarInicio(L,9);
	Imprimir(L);
	EliminaPrincipio(L);
	Imprimir(L);
	EliminaUltimo(L);
	Imprimir(L);
	AgregaFinal(L,7);
	Imprimir(L);	
	AgregaFinal(L,5);
	Imprimir(L);
	
}
/*----------------------------------------------Main---------------------------------------------------------*/
int Imprimir(pLista *L)
{
	int i=1;
	L->ventana=L->primero;
	if(L->longitud == 0){printf("Error no hay lista \n\n");}
	else
	{
		printf("LISTA:");
		while (i<=L->longitud)
		{
			printf("| %i ",L->ventana->inf);
			L->ventana=L->ventana->siguiente;
			i++;	
		}	
		printf("|\n\n");
	}
	printf("Longitud: %i \n",L->longitud);
}
