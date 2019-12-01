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
    int contadorC = 0;
    int contadorA = 0;
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
                if(contadorC == 0){
                    aux = controller_loadFromText("data.csv",listaEmpleados);
                    system("cls");
                    if(aux == 1){
                        contadorC = 1;
                        printf("Cantidad de elementos en la linkedList: %d\n\n",ll_len(listaEmpleados));
                    }
                    else printf("ERROR!\n\n");
                }
                else{
                    system("cls");
                    printf("ERROR! Ya ha sido cargado un archivo.\n\n");
                }
                break;
            case 2:
                if(contadorC == 0){
                    aux = controller_loadFromBinary("data.csv",listaEmpleados);
                    system("cls");
                    if(aux == 1){
                        printf("Cantidad de elementos en la linkedList: %d\n\n",ll_len(listaEmpleados));
                        contadorC = 1;
                    }
                    else printf("ERROR!\n\n");
                }
                else{
                    system("cls");
                    printf("ERROR! Ya ha sido cargado un archivo.\n\n");
                }
                break;
            case 3:
                system("cls");
                aux = controller_addEmployee(listaEmpleados);
                system("cls");
                if(aux == 1){
                    printf("Elementos anadidos exitosamente!\n\n");
                    contadorA = 1;
                }
                else printf("ERROR!\n\n");
                break;
            case 4:
                if(contadorA == 1 || contadorC == 1){
                    system("cls");
                    aux = controller_editEmployee(listaEmpleados);
                    system("cls");
                    if(aux == 1)printf("Elementos editados exitosamente!\n\n");
                    else printf("ERROR!\n\n");
                }
                else{
                    system("cls");
                    printf("ERROR! No se ha cargado ningun registro!\n\n");
                }
                break;
            case 5:
                if(contadorA == 1 || contadorC == 1){
                    system("cls");
                    aux = controller_removeEmployee(listaEmpleados);
                    system("cls");
                    if(aux == 1)printf("Accion realizada exitosamente!\n\n");
                    else printf("ERROR!\n\n");
                }
                else{
                    system("cls");
                    printf("ERROR! No se ha cargado ningun registro!\n\n");
                }
                break;
            case 6:
                if(contadorA == 1 || contadorC == 1){
                    system("cls");
                    aux = controller_ListEmployee(listaEmpleados);
                    printf("\n");
                    system("pause");
                    system("cls");
                    if(aux == 1)printf("Elementos mostrados exitosamente!\n\n");
                    else printf("ERROR!\n\n");
                }
                else{
                    system("cls");
                    printf("ERROR! No se ha cargado ningun registro!\n\n");
                }
                break;
            case 7:
                if(contadorA == 1 || contadorC == 1){
                    system("cls");
                    aux = controller_sortEmployee(listaEmpleados);
                    if(aux == 1)printf("Elementos ordenados exitosamente!\n\n");
                    if(aux == 2)printf("No se han producido cambios!\n\n");
                    else printf("ERROR!\n\n");
                }
                else{
                    system("cls");
                    printf("ERROR! No se ha cargado ningun registro!\n\n");
                }
                break;
            case 8:
                if(contadorA == 1 || contadorC == 1){
                    aux = controller_saveAsText("data.csv",listaEmpleados);
                    system("cls");
                    if(aux == 1)printf("Exito en la escritura!\n\n");
                    else printf("ERROR!\n\n");
                }
                else{
                    system("cls");
                    printf("ERROR! No se ha cargado ningun registro!\n\n");
                }
                break;
            case 9:
                if(contadorA == 1 || contadorC == 1){
                    aux = controller_saveAsBinary("data.csv",listaEmpleados);
                    system("cls");
                    if(aux == 1)printf("Exito en la escritura!\n\n");
                    else printf("ERROR!\n\n");
                }
                else{
                    system("cls");
                    printf("ERROR! No se ha cargado ningun registro!\n\n");
                }
                break;
            case 10:
                printf("\nFinalizando.\n");
                ll_deleteLinkedList(listaEmpleados);
                break;
            default:
                system("cls");
                printf("Ingreso Opcion Inexistente!\n\n");
        }
    }while(option != 10);
    return 0;
}
