#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmp.h"

#define TAM 1000

int main()
{
    eEmployee empleados[TAM];
    char salir = 'n';
    char nombre[51];
    char apellido[51];
    char auxStr[100];
    float salario;
    int sector;
    int id = 1000;
    int idSearch;
    int index;

    initEmployees(empleados, TAM);

    do{

    switch(menu()){

    case 1:

        //ALTAS

        printf("INGRESE NOMBRE: ");
        fflush(stdin);
        gets(auxStr);

        verifyString(auxStr, nombre, 51, "Error. Nombre muy largo, ingrese nuevamente: ");


        printf("INGRESE APELLIDO: ");
        fflush(stdin);
        gets(auxStr);
        verifyString(auxStr, apellido, 51, "Error. Apellido muy largo, ingrese nuevamente: ");

        printf("INGRESE SALARIO DEL EMPLEADO: ");
        scanf("%f", &salario);

        printf("INGRESE SECTOR DEL EMPLEADO: ");
        scanf("%d", &sector);

        if(addEmployee(empleados, TAM, id, nombre, apellido, salario, sector)==0){
            id++;
        }
        system("pause");
        break;

    case 2:
        //MODIFICACIONES

        if(verifyEmployee(empleados, TAM)==-1){

            printf("Error. Aun no hay empleados en el sistema\n");

        }else{

        printf("INGRESE ID: ");
        scanf("%d", &idSearch);
        index = findEmployeeById(empleados, TAM, idSearch);
        modifyEmployee(empleados, TAM, index);
        }

        system("pause");
        break;

    case 3:
        //BAJAS

        if(verifyEmployee(empleados, TAM)==-1){

            printf("Error. Aun no hay empleados en el sistema\n");

        }else{

        printf("INGRESE ID DEL EMPLEADO: ");
        scanf("%d", &idSearch);
        removeEmployee(empleados, TAM, idSearch);
        }
        system("pause");
        break;
    case 4:
        //INFORMES
        menuInformes(empleados, TAM);
        system("pause");
        break;
    case 5:
        printf("¿confirma salida? ingrese y/n ");
        fflush(stdin);
        scanf("%c", &salir);
        break;
    default:
        printf("opcion invalida\n");
        system("pause");
        fflush(stdin);

        }

    }while(salir=='n');

    return 0;
}
