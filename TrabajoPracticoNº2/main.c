#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define MAX 1000

int main(){
    Employee employee[MAX];
    initEmployees(employee,MAX);
    menu(employee,MAX);
    return 0;
}
