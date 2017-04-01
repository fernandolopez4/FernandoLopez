# include <stdio.h>
# include <stdlib.h>
# define matriz 8
////////////////////////////////////////////////////////////////////////////////////////////
void vector(int tablero[matriz])
{
	int f=1;
	while(f<=matriz)
	{	tablero[f]=0;
		f++;		}
	tablero[1]=1;
}
////////////////////////////////////////////////////////////////////////////////////////////
int posicion_erronea(int tablero[matriz],int posicion)
{
	int mal_posicion=0,i=1;
	while(i<posicion)
	{
		if((tablero[posicion]==tablero[i])||(i+tablero[i]==posicion+tablero[posicion])||(i-tablero[i]==posicion-tablero[posicion]))
		{
			mal_posicion=1;  i=posicion; }
		i=i+1;
	}
	if(mal_posicion==1)
	{	return(1);}
	else
	{	return(0);}
}
////////////////////////////////////////////////////////////////////////////////////////////
void corregir(int tablero[matriz])
{
	int i=1,j,cont;
	while(i<=matriz)
	{
		j=1;
		while(j<=matriz)
		{
			if(tablero[i]==j)
			{
				printf(" O ");}
			else
			{
				printf(" - ");	}
			j++;
		}
		i++;
		printf("\n");
	}

}
////////////////////////////////////////////////////////////////////////////////////////////
void jugar(int tablero[matriz],int *posicion,int *num)
{
	*posicion=*posicion+1;
	tablero[*posicion]=1;
	while(tablero[*posicion]<=matriz)
	{
		if(posicion_erronea(tablero,*posicion))
		{
			tablero[*posicion]+=1;
		}
		else
		{
			if(*posicion==matriz )
			{
				system("cls");printf("%i respuesta encontrada\n",*num);
				corregir(tablero);
				printf("---Pulse Enter para buscar otra respuesta posible---\n");
				fflush(stdin);getchar();
				*num=*num+1;return;
			}
			else
			{
				jugar(tablero,posicion,num);
				tablero[*posicion]=0;
				*posicion=*posicion-1;
				tablero[*posicion]=tablero[*posicion]+1;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
void main()
{
	int tablero[matriz],   posicion=0,   num=1;
	vector(tablero);
	jugar(tablero,&posicion,&num);
	printf("No hay mas respuestas en este tablero de %i x %i\n",matriz,matriz);
}
