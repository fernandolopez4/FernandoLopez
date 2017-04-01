#include <stdio.h>
#define peso_maximo 	15
#define n		5
//////////////////////////////////////////////////////////
void el_peso(int peso[n])
{
	peso[0]= 12;peso[1]= 2;peso[2]= 1;peso[3]= 4;peso[4]= 1;
}
////////////////////////////////////////////////////////
void el_beneficios(int beneficio[n])
{
	beneficio[0]= 4;beneficio[1]= 2;beneficio[2]= 2;beneficio[3]= 10;beneficio[4]= 1;
}
///////////////////////////////////////////////////////
void la_mochila(int mochila[n])
{	int i;
	for(i=0;i<n;i++){mochila[i]=0;}
}
///////////////////////////////////////////////////////
void imprimir_peso(int peso[n])
{	int i;
	printf("\n Peso       -->");for(i=0;i<n;i++){ printf("  %i  ", peso[i]);};printf("\n");
}
///////////////////////////////////////////////////////
void imprimir_beneficio(int beneficio[n])
{	int i;
	printf("\n Beneficios -->");for(i=0;i<n;i++){ printf("  %i  ", beneficio[i]);};printf("\n");
}
///////////////////////////////////////////////////////
void imprimir_mochila(int mochila[n])
{	int i;
	for(i=0;i<n;i++){ printf("  %i  ", mochila[i]);};printf("\n");
}
//////////////////////////////////////////
void seguir(int mochila[n],int *objeto, int *kilo, int *solucion,int peso[n],int beneficio[n]){
int i;
	//producto = n;
	for(i=n-1;i>-1;i--){
		if(mochila[i]==1){
			*objeto=i;mochila[*objeto]=0;
			*kilo=*kilo - peso[*objeto];
			*solucion = *solucion - beneficio[*objeto];
			i=-1;
		}
	}
}
///////////////////////////////////////////////////////
void imprimir_solucion(int mochila[n],int peso[n],int beneficio[n]){
int i, peso_total=0,ganancia_total=0;
	for(i=0;i<n;i++){
		if(mochila[i] ==1){peso_total= peso_total+peso[i]; ganancia_total=ganancia_total+beneficio[i];
		}
	}
	printf("\n El ladron te ha robado !! :");for(i=0;i<n;i++){ printf("  %i  ", mochila[i]);};printf("\n Peso %i ganancias %i\n",peso_total,ganancia_total);
}
////////////////////////////////////////////////////////////////////
void modulo_principal(int mochila[n], int peso[n],int beneficio[n] , int objeto , int kilo , int solucion ){
    int mejor_mochila[n];
	mejor_mochila[0]=0;mejor_mochila[1]=0;mejor_mochila[2]=0;mejor_mochila[3]=0;mejor_mochila[4]=0;
	while(objeto<n){
    objeto=objeto+1;
    if(objeto < n)
    {
            if(kilo+peso[objeto]<peso_maximo){
				       mochila[objeto]=1;
				       printf ("\n Producto valido.");
				       imprimir_mochila(mochila); ("\n");
				    if(objeto != n-1)
				    {
				        modulo_principal(mochila,peso,beneficio,objeto,kilo + peso[objeto],solucion + beneficio[objeto]);
                        seguir(mochila,&objeto,&kilo,&solucion,peso,beneficio);
                        imprimir_mochila(mochila);
			    	}
			    	else
			    	{
			    	    imprimir_mochila(mochila);
                        printf ("\n tablero guardado en la pila\n");
                        imprimir_mochila(mochila);
                        printf ("\n buscando otra solucion...");
                        seguir(mochila,&objeto,&kilo,&solucion,peso,beneficio);
                        imprimir_mochila(mochila);
                        getchar();
			    	}
			}
     }
          seguir(mochila,&objeto,&kilo,&solucion,peso,beneficio);
  }
}
////////////////////////////////////////////
main()
{	int peso[n], beneficio[n],mochila[n];
    printf ("Bienvenido al algoritmo La Mochila. \n");
	el_peso(peso);
	el_beneficios(beneficio);
	la_mochila(mochila);
	printf ("esta es la mochila\n");
	imprimir_mochila(mochila);	printf ("\n");
	modulo_principal(mochila,peso,beneficio,-1,0,0);
}
///////////////////////////////////////////
