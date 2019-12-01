#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "utn.h"

struct Aux{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
};

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    FILE *pFile;
    int r;

    char var1[50],var2[50],var3[50],var4[50];
    pFile = fopen(path,"r");

    if(pFile == NULL){
        return -1;
    }

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){
            Employee *this = employee_newParametros(var1, var2, var3, var4);
            ll_add(pArrayListEmployee,this);
        }
        else{
            break;
        }
    }while(!feof(pFile));

    fclose(pFile);
    return 1;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    FILE *pFile;
    struct Aux pers;
    int cant, i=0, aux=0;;
    char a[50], b[50], c[50];

    if((pFile = fopen(path,"rb"))==NULL){
		printf("No se pudo abrir el archivo");
		return -1;
	}

	while(!feof(pFile)){
        cant = fread(&pers,sizeof(pers),1,pFile);
        aux++;
        if(cant!=1){
            if(feof(pFile))
                break;
            else{
                printf("No leyo el ultimo registro");
                break;
            }
        }
	}

	rewind(pFile);
    printf("%d",aux);

    while(!feof(pFile) && i<(aux)-1){
        cant = fread(&pers,sizeof(pers),1,pFile);
        sprintf(a,"%d",pers.id);
        sprintf(b,"%d",pers.horasTrabajadas);
        sprintf(c,"%d",pers.sueldo);

        Employee *this = employee_newParametros(a, pers.nombre, b, c);
        ll_add(pArrayListEmployee,this);

        if(cant!=1){
            if(feof(pFile))
                break;
            else{
                printf("No leyo el ultimo registro");
                break;
            }
        }
        i++;
	}
	fclose(pFile);

    return 1;
}

int controller_addEmployee(LinkedList* pArrayListEmployee){
    char rta;
    int aux, auxC;
    float auxD;
    char a[50], b[50], c[50], d[50];
    Employee *pers;

    do{
        do{
            aux = getString(b,"Nombre: ","El largo debe ser entre 3 y 50",3,50);
            if(aux != 0) printf("\n\n");
        }while(aux != 0);

        do{
            aux = getInt(&auxC,"Horas Trabajadas: ","Rango valido [1 - 500]",1,500);
            if(aux != 0) printf("\n\n");
        }while(aux != 0);

        do{
            aux = getFloat(&auxD,"Sueldo: ","Rango valido [1 - 250000]",1,250000);
            if(aux != 0) printf("\n\n");
        }while(aux != 0);

        do{
            printf("\nIngresa mas usuarios? (s/n): ");
            fflush(stdin);
            scanf("%c",&rta);
            rta = tolower(rta);
        }while(rta != 's' && rta != 'n');

        pers = ll_get(pArrayListEmployee,ll_len(pArrayListEmployee)-1);
        aux = (pers->id)+1;

        sprintf(a,"%d",aux);
        sprintf(c,"%d",auxC);
        sprintf(d,"%f",auxD);

        Employee *this = employee_newParametros(a, b, c, d);
        ll_add(pArrayListEmployee,this);
        printf("\n\n");
    }while(rta == 's');
    return 1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee){
    int r;
    int aux;
    int opcion;
    int selec;
    int i;
    int noEsta = 0;
    int horasTrabajadas;
    char conf;
    char nombre[50];
    char a[50], b[50], c[50], d[50];
    float sueldo;
    Employee *pers2;
    Employee *pers;

    pers2 = ll_get(pArrayListEmployee,ll_len(pArrayListEmployee)-1);
    aux = (pers2->id);

    do{
        r = getInt(&opcion,"Que id desea modificar?: ","Rango valido [0 - Max Id]",1,aux);
        if(r != 0) printf("\n");
    }
    while(r != 0);

    do{
    for(i=0; i<ll_len(pArrayListEmployee); i++){
        pers = ll_get(pArrayListEmployee,i);
        if(pers->id == opcion){
            printf("\nDatos Obtenidos -> ");
            printf("%d - %s - %d - %.2f\n",employee_getId(pers),employee_getNombre(pers),
                                        employee_getHorasTrabajadas(pers),employee_getSueldo(pers));
            printf("\n");

            sprintf(a,"%d",pers->id);
            sprintf(b,"%s",pers->nombre);
            sprintf(c,"%d",pers->horasTrabajadas);
            sprintf(d,"%f",pers->sueldo);

            do{
                do{
                    r = getInt(&selec,
                        "* 1)Modificar nombre\n* 2)Modificar horas trabajadas\n* 3)Modificar sueldo\n*4)Salir\n Opcion: "
                        ,"Rango valido [0 - 4]",1,4);
                    if(r != 0) printf("\n");
                }
                while(r != 0);

                switch(selec){
                    case 1:
                        do{
                            aux = getString(nombre,"Nombre: ","El largo debe ser entre 3 y 50",3,50);
                            if(aux != 0) printf("\n\n");
                        }while(aux != 0);
                        sprintf(b,"%s",nombre);
                        break;
                    case 2:
                        do{
                            aux = getInt(&horasTrabajadas,"Horas Trabajadas: ","Rango valido [1 - 100]",1,100);
                            if(aux != 0) printf("\n\n");
                        }while(aux != 0);
                        sprintf(c,"%d",horasTrabajadas);
                        break;
                    case 3:
                        do{
                            aux = getFloat(&sueldo,"Sueldo: ","Rango valido [1 - 250000]",1,250000);
                            if(aux != 0) printf("\n\n");
                        }while(aux != 0);
                        sprintf(d,"%f",sueldo);
                        break;
                    case 4:
                        break;
                }
            }while(selec != 4);

            do{
                r = getChar(&conf,"Confirma la modificacion? [S][N]: ","Solo [S][N]",'S','N');
                if(conf == 'S') {
                    pers = employee_newParametros(a, b, c, d);
                    ll_set(pArrayListEmployee,i,pers);
                }
                if(r != 0) printf("\n");
            }while(r != 0);
            noEsta = 0;
            break;
        }
        noEsta = 1;
    }
    if(noEsta == 1)printf("ERROR! No se encontro dicha id.\n\n");
    }while(noEsta == 1);
    printf("\n");

    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee){
    int opcion;
    int r;
    int i;
    int aux;
    int noEsta = 0;
    char conf;
    Employee *pers;
    Employee *pers2;

    controller_ListEmployee(pArrayListEmployee);

    pers2 = ll_get(pArrayListEmployee,ll_len(pArrayListEmployee)-1);
    aux = (pers2->id);

    do{
    do{
        r = getInt(&opcion,"Que id desea remover?: ","Rango valido [0 - Max Id]",1,aux);
        if(r != 0) printf("\n");
    }
    while(r != 0);

    for(i=0; i<ll_len(pArrayListEmployee); i++){
        pers = ll_get(pArrayListEmployee,i);
        if(pers->id == opcion){
            printf("\nDatos Obtenidos -> ");
            printf("%d - %s - %d - %.2f\n",employee_getId(pers),employee_getNombre(pers),
                                        employee_getHorasTrabajadas(pers),employee_getSueldo(pers));

            do{
                r = getChar(&conf,"Confirma el borrado? [S][N]: ","Solo [S][N]",'S','N');
                if(conf == 'S') {
                    ll_remove(pArrayListEmployee,i);
                }
                if(r != 0) printf("\n");
            }while(r != 0);
            noEsta = 0;
            break;
        }
        noEsta = 1;
    }
    if(noEsta == 1)printf("ERROR! No se encontro dicha id.\n\n");
    }while(noEsta == 1);
    printf("\n");
    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee){
    Employee *pers;
    int i;

    printf("Elementos cargados en la LinkedList:\n\n");
    printf("ID - NOMBRE - HORAS - SUELDOS\n\n");
    for(i=0; i<ll_len(pArrayListEmployee); i++){
        pers = ll_get(pArrayListEmployee,i);
        printf("%d - %s - %d - %.2f\n",employee_getId(pers),employee_getNombre(pers),
                                        employee_getHorasTrabajadas(pers),employee_getSueldo(pers));
	}
    return 1;
}

int controller_ordenaPorId(void* emp1, void* emp2){
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL){
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->id > p2->id) retorno = 1;
        else if(p1->id < p2->id) retorno=-1;
        else retorno=0;
    }
    return retorno;
}

int controller_ordenaPorNombre(void* emp1, void* emp2){
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL){
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(strcmp(p1->nombre,p2->nombre)>0 )retorno = 1;
        else if(strcmp(p1->nombre,p2->nombre)<0) retorno=-1;
        else retorno=0;
    }
    return retorno;
}

int controller_ordenaPorSueldos(void* emp1, void* emp2){
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL){
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->sueldo > p2->sueldo) retorno = 1;
        else if(p1->sueldo < p2->sueldo) retorno=-1;
        else retorno=0;
    }
    return retorno;
}

int controller_ordenaPorHoras(void* emp1, void* emp2){
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL){
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->horasTrabajadas > p2->horasTrabajadas) retorno = 1;
        else if(p1->horasTrabajadas < p2->horasTrabajadas) retorno=-1;
        else retorno=0;
    }
    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int selec, selec2;
    int r;
    int retornar = 1;
    printf("Menu de seleccion: \n");

    do{
        r = getInt(&selec,
            "* 1)Ordenar por Nombres\n* 2)Ordenar por Horas Trabajadas\n* 3)Ordenar Por Sueldos\n* 4)Ordenar por Id\n* 5)Salir\n Opcion: "
            ,"Rango valido [1 - 5]",1,5);
        if(r != 0) {
            printf("\n");
        }
    }while(r != 0);

    printf("\n");
    if(selec != 5){
        do{
            r = getInt(&selec2,
                "* 0)Ordenar Descendente\n* 1)Ordenar Ascendente\n* 2)Salir\n Opcion: "
                ,"Rango valido [0 - 2]",0,2);
            if(r != 0) printf("\n");
        }while(r != 0);
    }

    if(selec2 == 2){
        system("cls");
        retornar = 2;
    }
    else{
    if(selec == 1){
        ll_sort(pArrayListEmployee,controller_ordenaPorNombre,selec2);
        system("cls");
        printf("Exito al ordenar!\n\n");
    }
    else{
        if(selec == 2){
            ll_sort(pArrayListEmployee,controller_ordenaPorHoras,selec2);
            system("cls");
            printf("Exito al ordenar!\n\n");
        }
        else{
            if(selec == 3){
                ll_sort(pArrayListEmployee,controller_ordenaPorSueldos,selec2);
                system("cls");
                printf("Exito al ordenar!\n\n");
            }
            else{
                if(selec == 4){
                    ll_sort(pArrayListEmployee,controller_ordenaPorId,selec2);
                    system("cls");
                    printf("Exito al ordenar!\n\n");
                }
                else retornar = 2;
            }
        }
    }
    }
    return retornar;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int i=0;
    FILE *pFile;
    struct Aux *pers;
    char a[50], b[50], c[50], d[50];

    if((pFile = fopen(path,"w"))==NULL){
		printf("No se pudo abrir el archivo");
		exit(1);
	}

	fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");

	printf("%d",ll_len(pArrayListEmployee));

	for(i=0; i<ll_len(pArrayListEmployee); i++){
        pers = ll_get(pArrayListEmployee,i);

        sprintf(a,"%d",pers->id);
        sprintf(b,"%s",pers->nombre);
        sprintf(c,"%d",pers->horasTrabajadas);
        sprintf(d,"%d",pers->sueldo);

        fprintf(pFile,"\n%s,%s,%s,%s",a,b,c,d);
	}
	fclose(pFile);
    return 1;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    int i;
    FILE *pFile;
    struct Aux *pers;

    if((pFile = fopen(path,"wb"))==NULL){
		printf("No se pudo abrir el archivo");
		exit(1);
	}

    for(i=0; i<ll_len(pArrayListEmployee); i++){
        pers = ll_get(pArrayListEmployee,i);
        fseek(pFile , 0L, SEEK_END);
        fwrite(pers,sizeof(*pers),1,pFile);
    }
    fclose(pFile);
    return 1;
}
