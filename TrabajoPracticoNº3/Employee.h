#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldosStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this);

int employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this);

int employee_setSueldo(Employee* this,float sueldo);
float employee_getSueldo(Employee* this);

#endif // employee_H_INCLUDED
