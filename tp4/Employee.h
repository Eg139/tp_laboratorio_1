#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief crea un nuevo empleado inicializado en vacio
 *
 * \return Employee*
 *
 */
Employee* newEmpleado();
/** \brief crea un nuevo empleado con valores
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \return Employee*
 *
 */
Employee* newEmpleadoParam(char* id, char* nombre, char* horasTrabajadas, char* sueldo);

/** \brief id setter
 *
 * \param employee Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* employee,int id);
/** \brief id getter
 *
 * \param employeeList Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* employeeList,int* id);

/** \brief nombre setter
 *
 * \param employee Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* employee,char* nombre);
/** \brief nombre getter
 *
 * \param employeeList Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* employeeList,char* nombre);

/** \brief horas setter
 *
 * \param employee Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas);
/** \brief horas getter
 *
 * \param employeeList Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* employeeList,int* horasTrabajadas);

/** \brief sueldo setter
 *
 * \param employee Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* employee,int sueldo);
/** \brief sueldo getter
 *
 * \param employeeList Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* employeeList,int* sueldo);

/** \brief compara los nombres para luego ordenarlos
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortByName(void* empleadoA, void* empleadoB);
/** \brief compara los id para luego ordenarlos
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortById(void* empleadoA, void* empleadoB);
/** \brief compara las horas trabajadas para luego ordenarlos
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortByHorasTrabajadas(void* empleadoA, void* empleadoB);
/** \brief compara los sueldos para luego ordenarlos
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 *
 */
int employeeSortBySueldo(void* empleadoA, void* empleadoB);


/** \brief muestra a un empleado
 *
 * \param pEmp Employee*
 * \return int
 *
 */
int mostrarEmpleado(Employee* pEmp);
/** \brief busca el id de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 *
 */
int employee_buscarId(LinkedList* pArrayListEmployee, int id);
/** \brief borra un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int
 *
 */
int employee_delete(LinkedList* pArrayListEmployee, int index);
/** \brief edita un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int
 *
 */
int employee_edit(LinkedList* pArrayListEmployee, int index);

int employeList_compare(LinkedList* this, LinkedList* this2);

int sobreescribir_employee(LinkedList* this);

int filtrar_horasTrabajadas(void* emp);

#endif // employee_H_INCLUDED
