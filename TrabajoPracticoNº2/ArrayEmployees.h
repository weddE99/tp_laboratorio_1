struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

/** \brief  Para indicar que todas las posiciones del array estan vacios.
*
* \param list Employee* puntero al array de Employee
* \param len int Array length
* \return int Return (0)
*
*/
int initEmployees(Employee* list, int len);

/** \brief agregar en una lista existente de empleados los valores recibidos como parámetros
*          en la primera posición vacía que se encuentre.
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (0)
*
*/
int addEmployee(Employee* list, int len, char name[], char lastName[], float salary, int sector);

/** \brief encuentra un empleado en Employee por la id, retorna la posicion del array del id.
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (id) si esta todo bien, (-1) si hay algun error.
*
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Elimina un empleado por id, (setea isEmpty en 0).
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) si no encuenta el id, (0) si esta ok.
*
*/
int removeEmployee(Employee* list, int len, int id);

/** \brief ordena los elementos del array Employee, el argumento indica si ascendente o descendente
*
* \param list Employee*
* \param len int
* \param order int [1] indicando ascendente - [2] indicando descendente
* \return int Return (0)
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief imprime el contenido del array de Employee
*
* \param list Employee*
* \param length int
* \return int Return (0)
*
*/
int printEmployees(Employee* list, int length);

/** \brief menu que se inicia al comenzar el programa, contiene las opciones de ingreso
*
* \param list Employee*
* \param length int
* \return int Return (0)
*
*/
void menu(Employee* list, int length);
