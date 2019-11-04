#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main(){
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado.\n");
        printf("4. Modificar datos de empleado.\n");
        printf("5. Baja de empleado.\n");
        printf("6. Listar empleados.\n");
        printf("7. Ordenar empleados.\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir.\n");
        printf("Ingrese opcion: ");
        scanf("%d",&option);

        switch(option){
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                system("cls");
                printf("Cantidad de elementos en la linkedList: %d\n\n",ll_len(listaEmpleados));
                break;
            case 2:
                controller_loadFromBinary("data.csv",listaEmpleados);
                system("cls");
                printf("Cantidad de elementos en la linkedList: %d\n\n",ll_len(listaEmpleados));
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                system("cls");
                printf("Exito en la escritura!\n\n");
                break;
            case 9:
                controller_saveAsBinary("data.csv",listaEmpleados);
                system("cls");
                printf("Exito en la escritura!\n\n");
                break;
            case 10:
                printf("\nFinalizando.\n");
                break;
            default:
                system("cls");
                printf("Ingreso Opcion Inexistente!\n\n");
        }
    }while(option != 10);
    return 0;
}
