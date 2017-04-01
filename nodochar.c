#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	char *cadena;
	struct Nodo *siguiente, *anterior;
}pNodo;

struct Nodo *primero=NULL;
struct Nodo *ultimo=NULL;

int Agregar(pNodo *nuevo,char palabra[])
{
	nuevo=malloc(sizeof(pNodo));
	nuevo->siguiente=nuevo->anterior=NULL;
	nuevo->cadena=palabra;
	if(primero==NULL)
	{
		primero=ultimo=nuevo;
	}
	else
	{
		ultimo->siguiente=nuevo;
		ultimo=nuevo;
	}
}

int main()
{
	pNodo *nuevo;
	Agregar(nuevo,NULL);
	Agregar(nuevo,"HOLA");
	nuevo=primero;
	while(nuevo!=NULL)
	{
		printf("%s \n",nuevo->cadena);
		nuevo=nuevo->siguiente;
	}
}
