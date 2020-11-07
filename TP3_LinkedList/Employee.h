#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete(Employee* this);

int employee_setId(Employee* employee,int id);
int employee_getId(Employee* employeeList,int* id);

int employee_setNombre(Employee* employee,char* nombre);
int employee_getNombre(Employee* employeeList,char* nombre);

int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* employeeList,int* horasTrabajadas);

int employee_setSueldo(Employee* employee,int sueldo);
int employee_getSueldo(Employee* employeeList,int* sueldo);

int employeeSortByName(void* empleadoA, void* empleadoB);
int employeeSortById(void* empleadoA, void* empleadoB);
int employeeSortByHorasTrabajadas(void* empleadoA, void* empleadoB);
int employeeSortBySueldo(void* empleadoA, void* empleadoB);

Employee* newEmpleadoParam(char* id, char* nombre, char* horasTrabajadas, char* sueldo);
Employee* newEmpleado();
int mostrarEmpleado(Employee* pEmp);


#endif // employee_H_INCLUDED
