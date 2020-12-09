#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "InputGenerico.h"
void Initcliente(cliente* listcliente, int tam){
    for(int i = 0; i < tam; i++){
        listcliente[i].id = -1;
    }
}

int ObtclienteById(cliente* listcliente, int tam,int id){
    int aux = -1;
    for(int i = 0; i < tam; i++){
        if(listcliente[i].id == id){
            aux = i;
            break;
        }
    }
    return aux;
}

void Altacliente(cliente* listcliente, int tam, int* id){
    int i=ObtclienteById(listcliente,tam,-1);

    if(i != -1){
        *id= *id+1;
        listcliente[i].id= *id;
        do{
            SetInt(&listcliente[i].cuil,"\nIngrese Cuil: ");
        }while(listcliente[i].cuil < 1000000000 || listcliente[i].cuil > 9999999999 );

        SetString(listcliente[i].nombre,"\nIngrese Nombre: ");

        SetString(listcliente[i].apellido,"\nIngrese Apellido: ");

    }else{
        Alerta("\nNo se encontro un cliente libre\n");
    }
}

void Modcliente(cliente* listcliente, int tam){
    int id;
    int i;
    Listarcliente(listcliente,tam);
    SetInt(&id,"Ingrese id: ");
    i= ObtclienteById(listcliente,tam,id);
    system("cls");

    if(i != -1 && id != -1){
        printf("\n1.NOMBRE\n2.APELLIDO\n3.CUIL\n");
        SetInt(&id,"Ingrese opcion: ");

        switch(id){
            case 1:
                SetString(listcliente[i].nombre,"\nIngrese Nombre: ");
                break;

            case 2:
                SetString(listcliente[i].apellido,"\nIngrese Apellido: ");
                break;

            case 3:
                do{
                    SetInt(&listcliente[i].cuil,"\nIngrese Cuil: ");
                }while(listcliente[i].cuil < 0 || listcliente[i].cuil > 9999999999 );
                break;

            default:
                Alerta("\nOpcion incorrecta\n");
                break;
        }
    }else{
        Alerta("\nEl id ingresado no existe\n");
    }
}

void Delcliente(cliente* listcliente, int tam){
    int id;
    int i;
    Listarcliente(listcliente,tam);
    SetInt(&id,"Ingrese id: ");
    i = ObtclienteById(listcliente,tam,id);
    system("cls");

    if(i != -1 && id != -1){
        listcliente[i].id = -1;
        Alerta("\nSe a eliminado correctamente\n");
    }else{
        Alerta("\nEl id ingresado no existe\n");
    }
}

void Printcliente(cliente cliente){
    printf("%d  %s  %s  %d\n",cliente.id, cliente.nombre, cliente.apellido, cliente.cuil);
}

void Listarcliente(cliente* listcliente, int tam){
    printf("ID  | NOMBRE  | APELLIDO  | CUIL \n");

    for(int i = 0; i < tam; i++){
        if(listcliente[i].id != -1){
            Printcliente(listcliente[i]);
        }
    }
}
