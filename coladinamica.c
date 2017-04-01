#include <stdio.h>
#include <stdlib.h>

typedef struct cola
{
	int info;
	struct cola *primero,*ultimo,*siguiente;
}*Nodo,*Cola;

Cola Iniccola()
{
	Cola cola=(Cola)malloc(sizeof(struct cola));
	cola->primero=cola->ultimo=NULL;
	return cola;
}

void Adiccola(Cola *cola)
{
	int numero;
	Nodo nueva;
	nueva=(Cola)malloc(sizeof(struct cola));
	printf("Numero:");scanf("%i",&numero);
	nueva->info=numero;
	nueva->siguiente=NULL;
	if ((*cola)->primero == NULL)
	{
		(*cola)->primero=(*cola)->ultimo=nueva;
	}
	else
	{
		(*cola)->ultimo->siguiente=nueva;
		(*cola)->ultimo=nueva;
	}
}

void Elimcola(Cola *cola)
{
	Nodo nueva;
   if((*cola)->primero!=NULL)
      {
	         if ((*cola)->primero->siguiente==NULL)
	         {
		            free((*cola)->primero);
		            (*cola)->primero=(*cola)->ultimo=NULL;
	          }
         	else
	          {
	         	    nueva=(*cola)->primero;
	         	    (*cola)->primero=nueva->siguiente;
	              	free(nueva);
	           }
      }
      else
      {
             printf("Lista Vacia\n");
        }
}

int Infocola(Cola *cola)
{
   if ((*cola)->primero!=NULL)
     	printf("Primer elemento: %i \n",(*cola)->primero->info);
   else
       printf("Lista Vacia\n");
}

void Vaciacola(Cola *cola)
{
	if ((*cola)->primero == NULL && (*cola)->ultimo ==NULL)
	{
		printf("Cola vacia \n"); 
	}
	else
	{
		printf("Cola en uso \n");
	}
}

void Destrcola(Cola *cola)
{
	while ((*cola)->primero!=NULL)
	{
		Nodo nueva;
		if ((*cola)->primero->siguiente==NULL)
		{
			free((*cola)->primero);
			(*cola)->primero=(*cola)->ultimo=NULL;
		}
		else
		{
			nueva=(*cola)->primero;
			(*cola)->primero=nueva->siguiente;
			free(nueva);
		}
	}
}

int main()
{
	Cola cola=Iniccola();
	int opcion;
	while (opcion != 6 )
	{
		printf("1.-Agregar elemento \n");
		printf("2.-Eliminar(Primero)\n");
		printf("3.-Retorna el primer elemento \n");
		printf("4.-Informa si la cola esta vacia \n");
		printf("5.-Destruir cola \n");
		printf("6.-Salir \n");
		printf("Ingresa Opcion: ");
		scanf("%i",&opcion);
		system("clear");
		if (opcion==1){Adiccola(&cola);}
		if (opcion==2){Elimcola(&cola);}
		if (opcion==3){Infocola(&cola);}
		if (opcion==4){Vaciacola(&cola);}
		if (opcion==5){Destrcola(&cola);}
		
	}
}
