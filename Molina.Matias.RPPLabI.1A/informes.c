#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "prestamos.h"
#include "InputGenerico.h"
void Printclienteprestamos(cliente cliente, int aux){
    printf("%d  %s  %s  %d  %d\n",cliente.id, cliente.nombre, cliente.apellido, cliente.cuil, aux);
}

void Listarclienteprestamos(cliente* listcliente,prestamo* listprestamo, int tam){
    int contador;
    printf("ID  | NOMBRE  | APELLIDO  | CUIL | P ACTIVOS \n");
    for(int i = 0; i < tam; i++){
        contador=0;
        for(int j=0;j<tam; j++){
            if(listprestamo[j].idcliente==listcliente[i].id && stricmp(listprestamo[j].estado,"ACTIVO")==0){
                contador++;
            }
        }
        if(listcliente[i].id != -1){
            Printclienteprestamos(listcliente[i],contador);
        }
    }
    system("pause");
}

void PrintprestamoCUIL(prestamo prestamo, int aux){
    printf("%d  %d  %d  %s  %d\n",prestamo.id, prestamo.importe, prestamo.cantCuotas, prestamo.estado, aux);
}

void ListarprestamoActCUIL(prestamo* listprestamo,cliente* listcliente, int tam){
    int aux;
    printf("ID | IMPORTE | CUOTAS | ESTADO | CUIL\n");

    for(int i = 0; i < tam; i++){
        aux=0;
        for(int j=0; j<tam;j++){
            if(listcliente[j].id==listprestamo[i].idcliente){
                aux=listcliente[j].cuil;
                break;
            }
        }
        if(listprestamo[i].id != -1 && stricmp(listprestamo[i].estado,"ACTIVO")==0){
            PrintprestamoCUIL(listprestamo[i],aux);
        }
    }
    system("pause");
}
void PrintclienteMas(cliente cliente, int aux){
    printf("%d  %s  %s  %d  %d\n\n",cliente.id, cliente.nombre, cliente.apellido, cliente.cuil, aux);
}

void ClienteMasActivos(cliente* listcliente,prestamo* listprestamo, int tam){
    int contador;
    int maximo=0;
    int indice;
    printf("CLIENTE CON MAS PRESTAMOS ACTIVOS\nID  | NOMBRE  | APELLIDO  | CUIL | P ACTIVOS \n");
    for(int i = 0; i < tam; i++){
        contador=0;
        if(listcliente[i].id != -1){
            for(int j=0;j<tam; j++){
                if(listprestamo[j].idcliente==listcliente[i].id && stricmp(listprestamo[j].estado,"ACTIVO")==0){
                    contador++;
                }
            }
        }
        if(contador>maximo){
            maximo=contador;
            indice=i;
        }
    }
    if(maximo>0){
        PrintclienteMas(listcliente[indice],maximo);
    }else if(maximo==0){
        printf("No hay clientes con prestamos activos\n\n");
    }
}

void ClienteMasSaldados(cliente* listcliente,prestamo* listprestamo, int tam){
    int contador;
    int maximo=0;
    int indice;
    printf("CLIENTE CON MAS PRESTAMOS SALDADOS\nID  | NOMBRE  | APELLIDO  | CUIL | P SALDADOS \n");
    for(int i = 0; i < tam; i++){
        contador=0;
        if(listcliente[i].id != -1){
            for(int j=0;j<tam; j++){
                if(listprestamo[j].idcliente==listcliente[i].id && stricmp(listprestamo[j].estado,"SALDADO")==0){
                    contador++;
                }
            }
        }
        if(contador>maximo){
            maximo=contador;
            indice=i;
        }
    }
    if(maximo>0){
        PrintclienteMas(listcliente[indice],maximo);
    }else if(maximo==0){
        printf("No hay clientes con prestamos saldados\n\n");
    }
}

void ClienteMasPrestamos(cliente* listcliente,prestamo* listprestamo, int tam){
    int contador;
    int maximo=0;
    int indice;
    printf("CLIENTE CON MAS PRESTAMOS\nID  | NOMBRE  | APELLIDO  | CUIL | PRESTAMOS \n");
    for(int i = 0; i < tam; i++){
        contador=0;
        if(listcliente[i].id != -1){
            for(int j=0;j<tam; j++){
                if(listprestamo[j].idcliente==listcliente[i].id){
                    contador++;
                }
            }
        }
        if(contador>maximo){
            maximo=contador;
            indice=i;
        }
    }
    if(maximo>0){
        PrintclienteMas(listcliente[indice],maximo);
    }else if(maximo==0){
        printf("No hay clientes con prestamos\n\n");
    }
    system("pause");
}
