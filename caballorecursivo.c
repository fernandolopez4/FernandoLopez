#include<stdlib.h>
#include<stdio.h>
#define filas 4
#define columnas 4
////////////////////////////////////////////////////////////////
void iniciar_tablero(int tablero[][columnas]  )
{
	int i,j;
	i=0;
	while(i<filas)
	{
		j=0;
		while(j<columnas)
		{
			tablero[i][j]=0;
			j++;
		}
		i++;
	}
}
////////////////////////////////////////////////////////////////
void poner_obstaculos (int tablero [][columnas])
{
    int i=0,j;
          while (i < filas )
          {
                j=0;
                        while (j < columnas)
                        {
                            if ((i==3) && (j==0))
                            {
                              tablero [i][j] = -1;
                            }
                                  if ( (i==7) && (j==1) )
                                  {
                                      tablero [i][j] = -1;
                                  }
                                      if ( (i==5) && (j==4) )
                                      {
                                         tablero [i][j] = -1;
                                      }
                            j++;
                        }
              i++;
          }
}
/////////////////////////////////////////////////////////////////
void imprimir_solucion(int tablero[][columnas])
{
	int i,j;
	i=0;
	while(i<filas)
	{
		j=0;
		while(j<columnas)
		{
			printf(" %i |"  ,  tablero[i][j]  ,    "   |   ");
			j++;
		}
		i++;
		printf("\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////
void buscar_posicion(int tablero[][columnas],int *x,int *y,int contador)
{
	int i,j;
	i=0;
	while(i<filas){
		j=0;
		while(j<columnas){
			if(tablero[i][j]==contador){
				*x=i;
				*y=j;
			}
			j++;
		}
		i++;
	}
}
/////////////////////////////////////////////////////////////////////////////////
int candidato_valido(int tablero[][columnas],int x,int y,int opcion)
{
	int posx[4]={0,1,0,-1},posy[4]={1,0,-1,0};
	if((0<=x+posx[opcion])&&(0<=y+posy[opcion])&&(x+posx[opcion]<filas)&&(y+posy[opcion]<columnas))
	{
		if(tablero[x+posx[opcion]][y+posy[opcion]]==0)
		{
			return(1);
		}
	}
			return(0);

}
////////////////////////////////////////////////////////////////////////
void busca_solucion(int tablero[][columnas],int x,int y,int contador)
{
	int opcion=0,tablero_aux[filas][columnas];
	int posx[4]={0,1,0,-1},posy[4]={1,0,-1,0};
	tablero[x][y] = contador;
	while(opcion<5)
	{
		if(candidato_valido(tablero,x,y,opcion))
		{
			tablero[x+posx[opcion]][y+posy[opcion]] = contador+1;
			printf (" movimiento \n");
            printf("%i y %i",x+posx[opcion],y+posy[opcion]);
            printf ("\n");
			if((x+posx[opcion]!=0) || (y+posy[opcion]!= 3))
			{
                 busca_solucion ( tablero,x+posx[opcion],y+posy[opcion],contador+1);
                 tablero[x+posx[opcion]][y+posy[opcion]] = 0;
                 imprimir_solucion(tablero);
			}
		    else
	     	{
		       imprimir_solucion(tablero);
               printf ("\n tablero guardado en la pila\n");
               imprimir_solucion(tablero);
               printf ("\n buscando otra solucion...");
               tablero[x+posx[opcion]][y+posy[opcion]] = 0;
               imprimir_solucion(tablero);
               getchar();
		    }
         }
		opcion++;
	}
}
///////////////////////////////////////////////////////////////////////
void main()
{
	int tablero[filas][columnas];
	iniciar_tablero(tablero);
	poner_obstaculos (tablero);
	printf ("\n");
	busca_solucion(tablero,0,0,1);
}
/////////////////////////////////////////////////////////////////
