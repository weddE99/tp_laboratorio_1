#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#define ESC 27

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
    int aux;
    char a[50], b[50], c[50], d[50];

    do{
        printf("Ingrese nombre: ");
        scanf("%s",b);
        printf("Ingrese horas trabajadas: ");
        scanf("%s",c);
        fflush(stdin);
        printf("Ingrese sueldo: ");
        scanf("%s",d);

        do{
            printf("\nIngresa mas usuarios? (s/n)");
            fflush(stdin);
            scanf("%c",&rta);
            rta = tolower(rta);
        }while(rta != 's' && rta != 'n');

        // temporal
        aux = (ll_len(pArrayListEmployee))+1;
        sprintf(a,"%d",aux);

        Employee *this = employee_newParametros(a, b, c, d);
        ll_add(pArrayListEmployee,this);
        printf("\n\n");
    }while(rta == 's');
    return 1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee){

    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee){

    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee){
    Employee *pers;
    int i;

    printf("Elementos cargados en la LinkedList:\n\n");
    for(i=0; i<ll_len(pArrayListEmployee); i++){
        pers = ll_get(pArrayListEmployee,i);
        printf("%d - %s - %d - %d\n",employee_getId(pers),employee_getNombre(pers),
                                        employee_getHorasTrabajadas(pers),employee_getSueldo(pers));
	}
    return 1;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee){

    return 1;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int i=0;
    FILE *pFile;
    Employee *pers;

    if((pFile = fopen(path,"w"))==NULL){
		printf("No se pudo abrir el archivo");
	}

	fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");

	for(i=0; i<ll_len(pArrayListEmployee); i++){
        pers = ll_get(pArrayListEmployee,i);
        fprintf(pFile,"\n%d,%s,%d,%d",employee_getId(pers),employee_getNombre(pers),
                                        employee_getHorasTrabajadas(pers),employee_getSueldo(pers));
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
	}

    for(i=0; i<ll_len(pArrayListEmployee); i++){
        pers = ll_get(pArrayListEmployee,i);
        fseek(pFile , 0L, SEEK_END);
        fwrite(pers,sizeof(*pers),1,pFile);
    }
    fclose(pFile);
    return 1;
}
