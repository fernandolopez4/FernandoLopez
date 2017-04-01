#include <stdio.h>
#include <stdlib.h>

typedef struct pNodo
{
	int inf;
	struct pNodo *anterior,*siguiente;
}*pNodo;

typedef struct Lista
{
	int longitud;
	pNodo primero,ventana,ultimo;
}*pLista;

/*-------------------Voids-ints-pLista-------------------------*/
pLista Iniclista();
void AnxLista(pLista *L);
int InfLista(pLista *L);
void InsLista(pLista *L);
void ElimLista(pLista*L);
void PrimLista(pLista *L);
void UltLista(pLista *L);
void SigLista(pLista *L);
int LongLista(pLista *L);
int InfoLista(pLista *L);
/*-------------------Voids-ints-pLista-------------------------*/

pLista Iniclista()
{
	pLista L;
	L = (pLista)malloc(sizeof(struct Lista));
	L->longitud = 0;
	L->primero = L->ventana = L->ultimo = NULL;
	return (L);
}

void AnxLista(pLista *L)
{
	int numero; pNodo nuevo;
	printf("Numero:");scanf("%i",&numero);
	nuevo=(pNodo)malloc(sizeof(struct pNodo)); /*Pedir memoria*/
	nuevo->inf = numero;
	nuevo->anterior = nuevo->siguiente = NULL;
	if ((*L)->longitud==0)
	{
		(*L)->primero=(*L)->ultimo=(*L)->ventana=nuevo;
	}
	else
	{
		if ((*L)->ventana==(*L)->ultimo)
		{
			(*L)->ventana->siguiente=(*L)->ultimo=nuevo;
			nuevo->anterior=(*L)->ventana;
		}
		else
		{
			nuevo->anterior=(*L)->ventana;
			nuevo->siguiente=(*L)->ventana->siguiente;
			(*L)->ventana->siguiente=nuevo;
		}
	}
	(*L)->ventana=nuevo;
	(*L)->longitud++;
}

void InsLista(pLista *L)
{
	int numero;pNodo nuevo;
	printf("Numero:");scanf("%i",&numero);
	nuevo=(pNodo)malloc(sizeof(struct pNodo));
	nuevo->inf=numero;
	nuevo->anterior=nuevo->siguiente=NULL;
	if((*L)->ventana==NULL)
	{
		(*L)->ventana=(*L)->ultimo=(*L)->primero=nuevo;
	}
	else
	{
		if((*L)->ventana==(*L)->primero)
		{
			nuevo->siguiente=(*L)->ventana;
			((*L)->ventana)->anterior=nuevo;
			(*L)->primero = nuevo;
		}
		else
		{
			nuevo->siguiente=(*L)->ventana;
			nuevo->anterior=((*L)->ventana)->anterior;
			(((*L)->ventana)->anterior)->siguiente=nuevo;
		}
	}
	(*L)->ventana=nuevo;
	(*L)->longitud++;
}

void ElimLista(pLista *L)
{
	pNodo nuevo;
	nuevo=(*L)->ventana;
	if((*L)->longitud == 0){printf("Error no hay lista");}
	else
	{
		if ((*L)->longitud==1)
		{
			(*L)->primero=(*L)->ventana=(*L)->ultimo=NULL;
		}
		else
		{
			if((*L)->ventana==(*L)->ultimo)
			{
				(*L)->ventana->anterior->siguiente=NULL;
				(*L)->ultimo=(*L)->ventana->anterior;
				(*L)->ventana=NULL;
			}
			else
			{
				(*L)->ventana->anterior->siguiente=(*L)->ventana->siguiente;
				(*L)->ventana->siguiente->anterior=(*L)->ventana->anterior;
				(*L)->ventana=(*L)->ventana->siguiente;
			}
		}
		free(nuevo);
		(*L)->longitud--;
	}
}


void PrimLista(pLista *L)
{
	if((*L)->longitud == 0){printf("Error no hay lista");}
	else
	{(*L)->ventana=(*L)->primero;}
}

void UltLista(pLista *L)
{
	if((*L)->longitud == 0){printf("Error no hay lista");}
	else
	{(*L)->ventana=(*L)->ultimo;}
}

void SigLista(pLista *L)
{
	if((*L)->longitud == 0){printf("Error no hay lista");}
	else
	{(*L)->ventana=(*L)->ventana->siguiente;}
}

void PosLista(pLista *L)
{
	int posicion,i=1;
	if((*L)->longitud == 0){printf("Error no hay lista");}
	else
	{
		printf("Posicion:");scanf("%i",&posicion);
		(*L)->ventana=(*L)->primero;
		while (i<posicion)
		{
			(*L)->ventana=(*L)->ventana->siguiente;
			i++;
		}
	}
}

int InfoLista(pLista *L)
{
	if((*L)->longitud == 0){printf("Error no hay lista");}
	else
	{
		printf("Ventana: %i \n",(*L)->ventana->inf);
	}
}

int LongLista(pLista *L)
{

	printf("Longitud: %i \n",(*L)->longitud);
}

/*----------------------------------------------Main---------------------------------------------------------*/
int main()
{
	pLista L=Iniclista();
	int Termino=0,opcion;
	while (Termino==0)
	{
		Ingresaropcion();
		printf("Opcion:");scanf("%i",&opcion);
		while (opcion>11)
		{
			printf("Opcion invalida \n");
			printf("Opcion:");scanf("%i",&opcion);
		}
		system("cls");
		//system("clear");
		if (opcion==1){AnxLista(&L);}
		if (opcion==2){InsLista(&L);}
		if (opcion==3){ElimLista(&L);}
		if (opcion==4){PrimLista(&L);}
		if (opcion==5){UltLista(&L);}
		if (opcion==6){SigLista(&L);}
		if (opcion==7){PosLista(&L);}
		if (opcion==8){InfoLista(&L);}
		if (opcion==9){LongLista(&L);}
		if (opcion==10){Imprimir(&L);}
		if (opcion==11){Termino=1;printf("Término del programa");}
	}
}
/*----------------------------------------------Main---------------------------------------------------------*/

int Ingresaropcion()
{
	printf("Ingresa la opcion deseada \n");
	printf("1.-Añadir un elemento despues de la ventana \n");
	printf("2.-agregar un elemento antes de la ventana \n");
	printf("3.-Eliminar elemento que se encuentra en la ventana \n");
	printf("4.-Colocar la ventana sobre el primer elemento de la lista \n");
	printf("5.-colocar la ventana sobre el ultimo elemento de la lista \n");
	printf("6.-Avanza la ventana una posicion \n");
	printf("7.-Coloca la ventana sobre el pos-esimo elemento de la lista \n");
	printf("8.-Retorna el elemento de la ventana \n");
	printf("9.-Longitud de la lista \n");
	printf("10.-Imprimir Lista \n");
	printf("11.-Salir \n");
}

int Imprimir(pLista *L)
{
	int i=1;pLista aux;
	aux=(*L)->ventana;
	(*L)->ventana=(*L)->primero;
	if((*L)->longitud == 0){printf("Error no hay lista \n\n");}
	else
	{
		printf("LISTA:");
		while (i<=(*L)->longitud)
		{
			printf("| %i ",(*L)->ventana->inf);
			(*L)->ventana=(*L)->ventana->siguiente;
			i++;
		}
		printf("|\n\n");
		(*L)->ventana=aux;
	}
}
