#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct cola
{
	int primero,ultimo,info[max];
}*Cola;

Cola Iniccola()
{
	Cola cola=(Cola)malloc(sizeof(struct cola));
	cola->primero=cola->ultimo=-1;
	return cola;
}

void Adiccola(Cola *cola)
{
	int numero;
	printf("NUMERO:");scanf("%i",&numero);
	if ((*cola)->primero ==-1)
	{
		(*cola)->info[0]=numero;
		(*cola)->primero=(*cola)->ultimo=0;
	}
	else
	{
		(*cola)->ultimo++;
		(*cola)->info[(*cola)->ultimo]=numero;
	}
}

void Elimcola(Cola *cola)
{
	if ((*cola)->primero==(*cola)->ultimo)
	{
		(*cola)->primero=(*cola)->ultimo=-1;
	}
	else
	{
		(*cola)->info[(*cola)->primero]=0;
		(*cola)->primero++;
	}
}

int Infocola(Cola *cola)
{
if((*cola)->primero!=-1)
{
	printf("primero: %i \n",(*cola)->info[(*cola)->primero]);
}
else
{
   printf("cola vacia\n");
}
}

int Vaciacola(Cola *cola)
{
	if ((*cola)->primero==-1 && (*cola)->ultimo==-1)
	{
		printf("Cola vacia \n\n");
	}
	else
	{
		printf("Cola en uso\n\n");
	}
}

int main ()
{
	Cola cola=Iniccola();
	int opcion;
	while (opcion !=6)
	{
		printf("1.-Agregar elemento \n");
		printf("2.-Eliminar(primero)\n");
		printf("3.-Retorna (primero) \n");
		printf("4.-Destruir cola \n");
		printf("5.-Retorna si la cola esta vacia \n");
		printf("6.-Salir \n");
		printf("Ingresa Opcion:");
		scanf("%i",&opcion);
		
		system("clear");
		if (opcion ==1){Adiccola(&cola);}
		if (opcion ==2){Elimcola(&cola);}
		if (opcion ==3){Infocola(&cola);}
		if (opcion==4)
		{
			while (cola->primero!=-1)
			{
				Elimcola(&cola);
			}
			printf("Pila elimanda \n\n");
		}
		if (opcion==5){Vaciacola(&cola);}
	}
}
Contact GitHub API Training Shop Blog About
© 2017 GitHub, Inc. Terms Privacy Security Status Help
