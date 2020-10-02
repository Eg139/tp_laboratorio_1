#define LIBRE 0
#define OCUPADO 1
#define BAJA -2
#include "Gets.h"
#include "Validate.h"
#define T 1000
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;


/** \brief shows the menu and all its options
 * \return void
 */
void menu();

/** \brief modify the employee characteristic that the user chooses
 * \param listado[] eEmployee
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 */
int modifyEmployee(eEmployee listado[], int len);

/** \brief Remove an Employee by Id
 * \param listado[] eEmployee
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 */
int removeEmployee(eEmployee listado[], int len);

/** \brief search places with free status
 * \param listado[] eEmployee
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 */
int searchFree(eEmployee listado[], int len);

/** \brief To indicate that all position in the array are empty
 * \param listado[] eEmployee
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 */
int initEmployees(eEmployee listado[], int len);

/** \brief
 *
 * \param texto[] char
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int menuUser(char texto[]);

/** \brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param listado[] eEmployee
 * \param len int
 * \param cont int
 * \return int Return (-1) if Error - (0) if Ok
 */
int addEmployees(eEmployee listado[], int len, int cont);

/** \brief print the content of employees array
 *
 * \param listado[] eEmployee
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int printEmployees(eEmployee listado[], int len);

/** \brief print the contents of the matrix of a single employee
 *
 * \param miEmployee eEmployee
 * \return void
 *
 */
void printEmployee(eEmployee miEmployee);

/** \brief create an employee
 *
 * \param id int
 * \return eEmployee
 *
 */
eEmployee createEmployee(int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param listado[] eEmployee
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int sortEmployees(eEmployee listado[], int len);

/** \brief data preload in the employee list
 * \param listado[] eEmployee
 * \return void
 *
 */
void hardCodear(eEmployee listado[]);

/** \brief shows the total salary of employees, their average and employees with higher than average salary
 *
 * \param listado[] eEmployee
 * \param len int
 * \return int int Return (-1) if Error - (0) if Ok
 *
 */
int showSalary(eEmployee listado[], int len);

/** \brief an Employee by Id en returns the index position in array.
 *
 * \param message[] char
 * \param listado[] eEmployee
 * \param len int
 * \return int int Return (-1) if Error - (0) if Ok
 *
 */
int findEmployeeById(char message[],eEmployee listado[], int len);
