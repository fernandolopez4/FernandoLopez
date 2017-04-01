#include<stdio.h>
#include<stdlib.h>


void menu (int *opcion);
void opciones(int *opcion);
void crea ();
void borrar ();
void agregar();
void reescribir();
void mostar();

main (){

    char respuesta='s';
    while(respuesta=='s'){
        int opcion;
        menu(&opcion);
        opciones(&opcion);
        printf("desea seguir? s/n\n");
        scanf("%s",&respuesta);


        }

}

void menu (int *opcion)
    {
        printf("Que opcion desea elegir?\n");
        printf("1.Crea un archivo vacio\n");
        printf("2.Borrar un archivo\n");
        printf("3.Agregar datos a un archivo\n");
        printf("4.Reescribir un archivo\n");
        printf("5.Mostrar contenido del archivo\n");
        scanf("%i",&*opcion);
    }

void opciones(int *opcion)
{
    if(*opcion==1){
        crea();
    }
    else {
        if (*opcion==2){
            borrar();
        }
        else{
            if(*opcion==3){
                agregar();
            }
            else {
                if(*opcion==4){
                    reescribir();
                }
                else{
                    if(*opcion==5){
                        mostar();
                    }
                }
            }
        }

    }
}

void crea ()          ///crear un archivo vacio///
{
        FILE *fp;
        fp = fopen ("mensaje.txt", "w");
        {printf("archivo creado exitosamente");}
        fclose(fp);
        }


void borrar ()         ///borrar un archivo///
{

    FILE *fp;
    if(fp==NULL){printf("Archivo no encontrado.\n");}
    else{printf("\nArchivo borrado satisfactoriamente.\n");}
    fp = remove("mensaje.txt");
    fclose(fp);


}

void agregar()         ///agregar datos a un archivo///
{
        char nombre[20];
        char elemento[250];
        printf("ingresa el nombre del archivo en el cual deses ingresar nueva informacion (mensaje.txt)\n");
        scanf("%s",&nombre);
        FILE *fp;
        fp = fopen (nombre, "a");
        if (fp==NULL){printf("file error");}
        printf("Ingresa algun elemento a tu lista\n");
        fflush(stdin);
            scanf("%[^\n]",&elemento);
        fprintf(fp,"%s",elemento);
        fclose(fp);


}

void reescribir()     ///reescribir un archivo///
{
        char nombre[20];
        char elemento[250];
        FILE *fp;
        fp = fopen ("mensaje.txt", "w");
        printf("Ingresa algun elemento a tu lista\n");
        fflush(stdin);
            scanf("%[^\n]",&elemento);
        fprintf(fp,"%s",elemento);
        if (fp==NULL){printf("file error");}
        fclose(fp);


}

void mostar()         ///mostrar contenido del archivo///
{
    FILE *fp;
    char dato[20];
    fp = fopen("mensaje.txt", "r");
    while(!feof(fp))
    {   fscanf(fp,"%s",dato);
        printf("\n %s string leido",dato);}
    fclose(fp);

}



