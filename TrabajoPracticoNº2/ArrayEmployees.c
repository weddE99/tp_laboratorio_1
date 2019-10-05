#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

void promedioGeneral(Employee* list, int len){
    int i;
    float promedioG = 0;
    int contador = 0;
    int contadorP = 0;
    float sumaProm = 0;
    for(i=0; i<len; i++){
        if(list[i].isEmpty == 0){
            sumaProm += list[i].salary;
            contador++;
        }
    }
    if(contador != 0){
        promedioG = sumaProm / contador;
    }
    else{
        promedioG = 0;
    }

    for(i=0; i<len; i++){
        if(list[i].isEmpty == 0){
            if(list[i].salary > promedioG){
                contadorP++;
            }
        }
    }
    printf("\n*  El promedio general es de: %.2f\n*  Hay %d empleado/s que supera el promedio general.\n\n",promedioG,contadorP);
}

int initEmployees(Employee* list, int len){
    int i;
    for(i=0; i<len; i++){
        list[i].isEmpty = 1;
    }
    return 0;
}

int addEmployee(Employee* list, int len, char name[], char lastName[], float salary, int sector){
    int i;
    int aux;
    char flag = 0;
    for(i=0; i<len; i++){
        aux = i;
        if(list[i].isEmpty == 1){
            list[i].id = aux+1;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            list[i].isEmpty = 0;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        return 0;
    }
    else{
        return -1;
    }
}

int editEmployee(Employee* list, int len, int id){
    int flag = 0;
    int i;
    int opcion;
    char conf;

    system("cls");
    for(i=0; i<len; i++){
        if(id == list[i].id){
            if(list[i].isEmpty == 0){
                printf("Datos encontrados: \n");
                printf("=============================================================\n");
                printf("%d\n%s\n%s\n%.2f\n%d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
                printf("=============================================================\n");

            do{
                printf("Confirma que desea modificar los datos? (S/N): ");
                fflush(stdin);
                scanf("%c",&conf);
                conf = tolower(conf);
            }while(conf != 's' && conf != 'n');

            if(conf == 's'){
                do{
                system("cls");
                printf("Datos encontrados: \n");
                printf("=============================================================\n");
                printf("%d\n%s\n%s\n%.2f\n%d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
                printf("=============================================================\n");
                printf("1)Modificar Nombre.\n2)Modificar Apellido.\n3)Modificar Sector.\n");
                printf("4)Modificar Salario.\n5)Salir.\nOpcion: ");
                scanf("%d",&opcion);

                switch(opcion){
                    case 1:
                        system("cls");
                        printf("Nombre: ");
                        scanf("%s",list[i].name);
                        break;
                    case 2:
                        system("cls");
                        printf("Apellido: ");
                        scanf("%s",list[i].lastName);
                        break;
                    case 3:
                        system("cls");
                        printf("Sector: ");
                        scanf("%d",&list[i].sector);
                        break;
                    case 4:
                        system("cls");
                        printf("Salario: ");
                        scanf("%f",&list[i].salary);
                        break;
                    case 5:
                        break;
                    default:
                        system("cls");
                        printf("\nOpcion Incorrecta!\n");
                    }
                }while(opcion != 5);
                flag = 1;
            }
            }
            break;
        }
    }
    if(flag != 1){
        printf("No se ha encontrado dicho id!");
        return -1;
    }
    else{
        return 0;
    }
}

int findEmployeeById(Employee* list, int len, int id){
    int flag = 0;
    int i;
    for(i=0; i<len;i++){
        if(id == list[i].id){
            if(list[i].isEmpty == 0){
                printf("Datos encontrados: \n");
                printf("=============================================================\n");
                printf("%d\t%s\t%s\t%.2f\t%d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
                printf("=============================================================\n");
                flag = 1;
            }
        }
    }
    if(flag == 1){
        return id;
    }
    else{
        return -1;
    }
}

int removeEmployee(Employee* list, int len, int id){
    int i;
    int flag = 0;
    char conf;
    i = findEmployeeById(list, len, id);
        if(i != -1){
            do{
                printf("Confirma que desea borrar los datos? (S/N): ");
                fflush(stdin);
                scanf("%c",&conf);
                conf = tolower(conf);
            }while(conf != 's' && conf != 'n');

            if(conf == 's'){
                list[i-1].isEmpty = 1;
                flag = 1;
                system("cls");
                printf("\nLos datos se han borrado exitosamente!\n\n");
            }
        }
    if(flag == 0){
        system("cls");
        printf("No se ha encontrado dicha id!\n\n");
        return -1;
    }
    return 0;
}

int sortEmployees(Employee* list, int len, int order){
    int i;
    int j;
    Employee auxList;

    if(order == 1){
        for(i=0;i<len-1;i++){
            if(list[i].isEmpty == 0){
            for(j=i+1;j<len;j++){
                if(list[j].isEmpty == 0){
                if(list[i].sector > list[j].sector){
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
                if(list[i].sector == list[j].sector){
                    if(strcmp(list[i].lastName,list[j].lastName)>0){
                        auxList = list[i];
                        list[i] = list[j];
                        list[j] = auxList;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName)==0){
                        if(strcmp(list[i].name,list[j].name)>0){
                            auxList = list[i];
                            list[i] = list[j];
                            list[j] = auxList;
                        }
                    }
                }
                }
            }
        }
        }
        printEmployees(list, len);
    }
    if(order == 2){
        for(i=0;i<len-1;i++){
            if(list[i].isEmpty == 0){
            for(j=i+1;j<len;j++){
                if(list[j].isEmpty == 0){
                if(list[i].sector < list[j].sector){
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
                if(list[i].sector == list[j].sector){
                    if(strcmp(list[i].lastName,list[j].lastName)<0){
                        auxList = list[i];
                        list[i] = list[j];
                        list[j] = auxList;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName)==0){
                        if(strcmp(list[i].name,list[j].name)<0){
                            auxList = list[i];
                            list[i] = list[j];
                            list[j] = auxList;
                        }
                    }
                }
                }
            }
        }
        }
        printEmployees(list, len);
    }
    promedioGeneral(list,len);
    return 0;
}

int printEmployees(Employee* list, int len){
    int i;
    system("cls");
    printf("Empleados Ingresados: \n");
    printf("=============================================================\n");
    for(i=0; i<len; i++){
        if(list[i].isEmpty == 0){
            printf("%d\t%s\t%s\t%.2f\t%d\n",
                list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    printf("=============================================================\n");
    return 0;
}

void menu(Employee* list, int len){
    int contador = 0;
    int opc;
    int id;
    int cName;
    int cApe;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    do{
        printf("==================\n1)Alta.\n2)Modificar.\n3)Baja.\n4)Informar.\n5)Salir.\n==================\nOpcion: ");
        scanf("%d",&opc);

        switch(opc){
            case 1:
                system("cls");

                do{
                    printf("Nombre: ");
                    scanf("%s",name);
                    cName = strlen(name);
                }while(cName > 51);

                do{
                    printf("Apellido: ");
                    scanf("%s",lastName);
                    cApe = strlen(lastName);
                }while(cApe > 51);

                do{
                    printf("Salario: ");
                    scanf("%f",&salary);
                }while(salary <= 0);

                do{
                    printf("Sector\n* 1)IT\n* 2)Mesa de Ayuda\n* 3)Recursos Humanos\n* 4)Ventas\n* 5)Finanzas\n\n");
                    printf("Opcion: ");
                    scanf("%d",&sector);
                }while(sector <= 0 || sector > 5);
                addEmployee(list, len, name, lastName, salary, sector);
                contador = 1;
                system("cls");
                break;
            case 2:
                if(contador != 0){
                    system("cls");
                    printEmployees(list,len);
                    printf("Ingrese la id a modificar: ");
                    scanf("%d",&id);
                    editEmployee(list, len, id);
                    system("cls");
                }
                else{
                    system("cls");
                    printf("Primero Ingrese alguna carga de empleado!!\n\n");
                }
                break;
            case 3:
                if(contador != 0){
                    system("cls");
                    printEmployees(list, len);
                    printf("Ingrese la id a dar de baja: ");
                    scanf("%d",&id);
                    removeEmployee(list, len, id);
                }
                else{
                    system("cls");
                    printf("Primero Ingrese alguna carga de empleado!!\n\n");
                }
                break;
            case 4:
                if(contador != 0){
                    system("cls");
                    printf("Ordenado Alfabeticamente\n1)Ascendente\n2)Descendente.\nOpcion: ");
                    scanf("%d",&opc);
                    sortEmployees(list, len, opc);
                }
                else{
                    system("cls");
                    printf("Primero Ingrese alguna carga de empleado!!\n\n");
                }
                break;
            case 5:
                break;
            default:
                system("cls");
                printf("Opcion Incorrecta!\n\n");
        }
    }while(opc != 5);
}
