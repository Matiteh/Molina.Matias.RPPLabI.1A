#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "prestamos.h"
#include "InputGenerico.h"
#include "informes.h"
#define TAM 50
int main()
{
    int id = 0;
    int idP=0;
	int opcion = 0;
	cliente listcliente[TAM];
	prestamo listprestamo[TAM];
	Initcliente(listcliente, TAM);
	Initprestamo(listprestamo,TAM);
    while(opcion != 10){
        printf("MENU ABM FINANCIERA\n\n1.ALTA CLIENTE\n2.MODIFICAR CLIENTE\n3.BAJA CLIENTE\n4.PRESTAMO\n5.SALDAR PRESTAMO\n6.REANUDAR PRESTAMO\n7.IMPRIMIR CLIENTES\n8.IMPRIMIR PRESTAMOS\n9.INFORMES\n10.SALIR\n");
        SetInt(&opcion,"Ingrese Opcion: ");
        system("cls");
        switch(opcion){

        case 1:
            Altacliente(listcliente,TAM,&id);
            break;
        case 2:
            Modcliente(listcliente,TAM);
            break;
        case 3:
            Delcliente(listcliente,TAM);
            break;
        case 4:
            Altaprestamo(listprestamo, TAM, &idP,listcliente, TAM);
            break;
        case 5:
            Saldarprestamo(listprestamo,listcliente, TAM);
            break;
        case 6:
            Reanudarprestamo(listprestamo,listcliente, TAM);
            break;
        case 7:
            Listarclienteprestamos(listcliente,listprestamo,TAM);
            break;
        case 8:
            ListarprestamoActCUIL(listprestamo,listcliente, TAM);
            break;
        case 9:
            ClienteMasActivos(listcliente,listprestamo,TAM);
            ClienteMasSaldados(listcliente,listprestamo,TAM);
            ClienteMasPrestamos(listcliente,listprestamo,TAM);
            break;
        case 10:
            break;
        default:
            Alerta("\nOpcion incorrecta\n");
            break;
        }
        system("cls");
    }
    return 0;
}
