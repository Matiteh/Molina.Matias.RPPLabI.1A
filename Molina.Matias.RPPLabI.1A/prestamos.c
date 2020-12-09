#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "prestamos.h"
#include "InputGenerico.h"
#define S "SALDADO"
#define A "ACTIVO"
void Initprestamo(prestamo* listprestamo, int tam){
    for(int i = 0; i < tam; i++){
        listprestamo[i].id = -1;
    }
}

int ObtprestamoById(prestamo* listprestamo, int tam,int id){
    int aux = -1;
    for(int i = 0; i < tam; i++){
        if(listprestamo[i].id == id){
            aux = i;
            break;
        }
    }
    return aux;
}

void Altaprestamo(prestamo* listprestamo, int tamA, int* id,cliente* listcliente, int tamC){
    int i = ObtprestamoById(listprestamo,tamA,-1);
    if(i != -1){
        *id = *id + 1;
        listprestamo[i].id = *id;

        do{
            system("cls");
            Listarcliente(listcliente,tamC);
            SetInt(&listprestamo[i].idcliente,"\nIngrese id cliente: ");
        }while(ObtclienteById(listcliente,tamC,listprestamo[i].idcliente) == -1 || listprestamo[i].idcliente < 0);

        do{
            SetInt(&listprestamo[i].importe,"\nIngrese Importe: ");
        }while(listprestamo[i].importe < 0 );

        do{
            SetInt(&listprestamo[i].cantCuotas,"\nIngrese Cuotas: ");
        }while(listprestamo[i].cantCuotas < 0 );

        strcpy(listprestamo[i].estado,A);

    }else{
        Alerta("\nNo hay prestamos libres\n");
    }
}

void Saldarprestamo(prestamo* listprestamo,cliente* listcliente, int tam){
    int id;
    int i;
    int iC;
    char aux='n';
    ListarprestamoAct(listprestamo,tam);
    SetInt(&id,"Ingrese id: ");
    i = ObtprestamoById(listprestamo,tam,id);
    system("cls");

    iC=ObtclienteById(listcliente,tam,listprestamo[i].idcliente);
    if(iC!=-1 && stricmp(listprestamo[i].estado,A)==0){
        printf("CLIENTE AL QUE PERTENECE\n");
        Printcliente(listcliente[iC]);
        SetChar(&aux,"\nIngrese 's' para confirmar y 'n' para volver al menu\n");
    }
    if(i != -1 && id != -1 && aux != 'n' && stricmp(listprestamo[i].estado,A)==0){
       strcpy(listprestamo[i].estado,S);
    }else{
        Alerta("\nNo existe el id ingresado\n");
    }
}

void Reanudarprestamo(prestamo* listprestamo,cliente* listcliente, int tam){
    int id;
    int i;
    int iC;
    char aux='n';
    ListarprestamoSald(listprestamo,tam);
    SetInt(&id,"Ingrese id: ");
    i = ObtprestamoById(listprestamo,tam,id);
    system("cls");

    iC=ObtclienteById(listcliente,tam,listprestamo[i].idcliente);
    if(iC!=-1 && stricmp(listprestamo[i].estado,A)==0){
        printf("CLIENTE AL QUE PERTENECE\n");
        Printcliente(listcliente[iC]);
        SetChar(&aux,"\nIngrese 's' para confirmar y 'n' para volver al menu\n");
    }

    if(i != -1 && id != -1 && aux != 'n' && stricmp(listprestamo[i].estado,S)==0){
       strcpy(listprestamo[i].estado,A);
    }else{
        Alerta("\nNo existe el id ingresado\n");
    }
}

void Printprestamo(prestamo prestamo){
    printf("%d  %d  %d  %s\n",prestamo.id, prestamo.importe, prestamo.cantCuotas, prestamo.estado);
}

void Listarprestamo(prestamo* listprestamo, int tam){
    printf("ID | IMPORTE | CUOTAS  | ESTADO\n");

    for(int i = 0; i < tam; i++){
        if(listprestamo[i].id != -1){
            Printprestamo(listprestamo[i]);
        }
    }
}

void ListarprestamoAct(prestamo* listprestamo, int tam){
    printf("ID | IMPORTE | CUOTAS | ESTADO\n");

    for(int i = 0; i < tam; i++){
        if(listprestamo[i].id != -1 && stricmp(listprestamo[i].estado,A)==0){
            Printprestamo(listprestamo[i]);
        }
    }
}

void ListarprestamoSald(prestamo* listprestamo, int tam){
    printf("ID | IMPORTE | CUOTAS | ESTADO\n");

    for(int i = 0; i < tam; i++){
        if(listprestamo[i].id != -1 && stricmp(listprestamo[i].estado,S)==0){
            Printprestamo(listprestamo[i]);
        }
    }
}
