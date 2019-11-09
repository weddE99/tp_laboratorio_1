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
    int aux;
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
                aux = controller_loadFromText("data.csv",listaEmpleados);
                system("cls");
                if(aux == 1)printf("Cantidad de elementos en la linkedList: %d\n\n",ll_len(listaEmpleados));
                else printf("ERROR!\n\n");
                break;
            case 2:
                aux = controller_loadFromBinary("data.csv",listaEmpleados);
                system("cls");
                if(aux == 1)printf("Cantidad de elementos en la linkedList: %d\n\n",ll_len(listaEmpleados));
                else printf("ERROR!\n\n");
                break;
            case 3:
                system("cls");
                aux = controller_addEmployee(listaEmpleados);
                system("cls");
                if(aux == 1)printf("Elementos anadidos exitosamente!\n\n");
                else printf("ERROR!\n\n");
                break;
            case 4:
                system("cls");
                aux = controller_editEmployee(listaEmpleados);
                system("cls");
                if(aux == 1)printf("Elementos borrados exitosamente!\n\n");
                else printf("ERROR!\n\n");
                break;
            case 5:
                break;
            case 6:
                system("cls");
                aux = controller_ListEmployee(listaEmpleados);
                if(aux == 1)printf("\nElementos mostrados exitosamente!\n\n");
                else printf("ERROR!\n\n");
                break;
            case 7:
                system("cls");
                aux = controller_sortEmployee(listaEmpleados);
                if(aux == 1)printf("Elementos ordenados exitosamente!\n\n");
                else printf("ERROR!\n\n");
                break;
            case 8:
                aux = controller_saveAsText("data.csv",listaEmpleados);
                system("cls");
                if(aux == 1)printf("Exito en la escritura!\n\n");
                else printf("ERROR!\n\n");
                break;
            case 9:
                aux = controller_saveAsBinary("data.csv",listaEmpleados);
                system("cls");
                if(aux == 1)printf("Exito en la escritura!\n\n");
                else printf("ERROR!\n\n");
                break;
            case 10:
                printf("\nFinalizando.\n");
                ll_deleteLinkedList(listaEmpleados);
                break;
            default:
                system("cls");
                printf("Ingreso de Opcion Inexistente!\n\n");
        }
    }while(option != 10);
    return 0;
}
