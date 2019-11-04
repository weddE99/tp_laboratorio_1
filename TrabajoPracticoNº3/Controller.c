#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

struct Aux{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
};

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    // parser
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
            //printf("\n%s\t%s\t%s\t%s\n",var1,var2,var3,var4);
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
		exit(1);
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
        //printf("\n%d\t%s\t%d\t%d\n",pers.id,pers.nombre,pers.horasTrabajadas,pers.sueldo);
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
    return 1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee){
    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee){
    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee){
    // conviene armar una struct estatica y cargar los datos desde linkedlist.
    return 1;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee){
    return 1;
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
        //printf("\n%d\t%s\t%d\t%d\n",pers->id,pers->nombre,pers->horasTrabajadas,pers->sueldo);
        fwrite(pers,sizeof(*pers),1,pFile);
    }
    fclose(pFile);
    return 1;
}
