#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Profesor;

/** \brief crea un nuevo empleado inicializado en vacio
 *
 * \return Profesor*
 *
 */
Profesor* newEmpleado();
/** \brief crea un nuevo empleado con valores
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \return Profesor*
 *
 */
Profesor* newEmpleadoParam(char* id, char* nombre, char* horasTrabajadas, char* sueldo);

/** \brief id setter
 *
 * \param employee Profesor*
 * \param id int
 * \return int
 *
 */
int employee_setId(Profesor* employee,int id);
/** \brief id getter
 *
 * \param employeeList Profesor*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Profesor* employeeList,int* id);

/** \brief nombre setter
 *
 * \param employee Profesor*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Profesor* employee,char* nombre);
/** \brief nombre getter
 *
 * \param employeeList Profesor*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Profesor* employeeList,char* nombre);

/** \brief horas setter
 *
 * \param employee Profesor*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Profesor* employee,int horasTrabajadas);
/** \brief horas getter
 *
 * \param employeeList Profesor*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Profesor* employeeList,int* horasTrabajadas);

/** \brief sueldo setter
 *
 * \param employee Profesor*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Profesor* employee,int sueldo);
/** \brief sueldo getter
 *
 * \param employeeList Profesor*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Profesor* employeeList,int* sueldo);

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
 * \param pEmp Profesor*
 * \return int
 *
 */
int mostrarEmpleado(Profesor* pEmp);
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
//int filtrar_Sueldo(void* emp);

#endif // employee_H_INCLUDED
