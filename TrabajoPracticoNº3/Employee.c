#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(){
    Employee *this = malloc(sizeof(Employee));
    return this;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldosStr){
    int id, horas;
    float sueldos;
    id = atoi(idStr);
    horas = atoi(horasTrabajadasStr);
    sueldos = atof(sueldosStr);

    Employee *this = employee_new();
    employee_setId(this,id);
    employee_setNombre(this,nombreStr);
    employee_setHorasTrabajadas(this,horas);
    employee_setSueldo(this,sueldos);

    return this;
}

int employee_setId(Employee* this,int id){
    if(id >0) {
        this->id = id;
    }
    return 0;
}

int employee_getId(Employee* this){
    return this->id;
}

int employee_setNombre(Employee* this,char* nombre){
    strcpy(this->nombre,nombre);
    return 0;
}

char* employee_getNombre(Employee* this){
    return this->nombre;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    if(horasTrabajadas >0){
        this->horasTrabajadas = horasTrabajadas;
    }
    return 0;
}

int employee_getHorasTrabajadas(Employee* this){
    return this->horasTrabajadas;
}

int employee_setSueldo(Employee* this,float sueldo){
    if(sueldo >0){
        this->sueldo = sueldo;
    }
    return 0;
}

float employee_getSueldo(Employee* this){
    return this->sueldo;
}

