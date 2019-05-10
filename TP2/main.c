#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define SIZEEMP 15
#define SIZESEC 5

typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

typedef struct{
    int id;
    char description[21];
} eSector;

int menu();
int menuInfo();
int menuAlphabet();
int findFree(eEmployee list[], int len);

//int removeEmployee(eEmployee list[], int len, int id);
int printEmployees(eEmployee list[], int len);
void hardcordEmployee(eEmployee list[], int len);
void hardcordSector(eSector sec[], int len);
void printEmployee(eEmployee list);
void initEmployees(eEmployee list[], int len);
void findEmployeeById(eEmployee list[], int len, int id);
void highEmployee(eEmployee list[], int len);
void removeEmployee(eEmployee list[], int len);
void sortEmployeesUpward(eEmployee list[], int len);
void modifyEmployee(eEmployee list[], int len);


int main()
{
    char seguir = 's';
    char confirmar;
    int order;
    int file;

    eEmployee employee[SIZEEMP];
   // eSector sectors[SIZESEC];
//-----------------------LLAMADA DE FUNCIONES-----------/
    hardcordEmployee(employee, SIZEEMP);
    //hardcordSector(sectors, SIZESEC);
 // initEmployees(employee, SIZEEMP);

    do
    {
        switch(menu())
        {
        case 1:
            //printf("\nAlta empleado\n");
            highEmployee(employee, SIZEEMP);
            system("pause");
            break;

        case 2:
            //printf("\nBaja empleado\n");

            removeEmployee(employee, SIZEEMP);
            system("pause");
            break;

        case 3:
            //printf("\nModificar empleado\n");
            modifyEmployee(employee, SIZEEMP);
            system("pause");
            break;
        case 4:
           printEmployees(employee, SIZEEMP);
            system("pause");
            break;
        case 5:
            findEmployeeById(employee, SIZEEMP, file);
            system("pause");
            break;
        case 6:
            switch(menuInfo()){
                case 1:
                        switch(menuAlphabet()){
                            case 1:
                                    sortEmployeesUpward(employee, SIZEEMP);
                                break;
                            case 2:

                                break;
                      }
                      break;
                case 2:
                      printf("Total empleados y promedio de sueldos: ");
                      break;
                case 3:
                      printf("Empleados que superan el sueldopromedio: ");
                      break;
            }
            system("pause");
            break;

        case 7:
            printf("\nConfirmar salida ??  S o N:");
            fflush(stdin);
            confirmar = getche();

            if(tolower(confirmar) == 's'){
                seguir = 'n';
            }
            system("\npause\n");
            break;

        default:
            printf("\nOpcion invalida. Reingrese opcion.\n\n");
           system("pause");
        }
    }
    while(seguir == 's');
    return 0;
}

int menu(){
    int option;

    system("cls");
    printf("************* TRABAJO PRACTICO 2 *************\n");
    printf("*************        ABM         *************\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion\n");
    printf("4- Mostrar Empleados\n");
    printf("5- Buscar Empleado\n");
    printf("6- Informar\n");
    printf("7- Salir\n\n");
    printf("\nIngrese Opcion: ");
    scanf("\n%d", &option);

    return option;
}

int menuInfo(){
    int option;
    system("cls");
    printf("\n************* INFORMES *************\n\n");
    printf("1- Total de Empleados\n");
    printf("2- Ordenar y mostrar por Apellido y Sector\n");
    printf("3- Mostrar por promedio de sueldo\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &option);

    return option;
}

int menuAlphabet(){
    int option;

    system("cls");
    printf("************* MOSTRAR EMPLEADOS POR APELLIDO Y SECTOR *************\n\n");
    printf("1- ASCENDENTE\n");
    printf("2- DESCENDENTE\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &option);

    return option;
}

void hardcordEmployee(eEmployee list[], int len){
    eEmployee auxEmp[]={
        {1, "Hernesto", "Guevara",  25000, 1, 1},
        {2,    "Pablo",  "Cepeda",  30000, 2, 1},
        {3,     "Luis",   "Lopez",  25000, 3, 1},
        {4,      "Ana",    "Soto",  37000, 4, 1},
        {5,    "Sofia", "Guevara",  20000, 5, 1},
        {6,    "Lucas",   "Elano",  40000, 1, 1},
        {7,    "Carla", "Pascual",  34000, 2, 1},
        {8,   "Andres", "Montiel",  37000, 3, 1},
        {9,   "Romina",   "Perez",  21000, 4, 1},
        {10, "Claudio",   "Gallo",  33000, 5, 1},
        {11,  "Karina",   "Perez",  45000, 1, 1},
        {12,    "Ayde",  "Chacon",  23000, 2, 1},
        {13, "Gustavo",   "Perez",  28000, 3, 1},
        {14, "Ezequiel",   "Posta", 35000, 4, 0},
        {15, "Liliana",  "Guerra",  34000, 5, 1}
    };
    for(int i=0; i<len; i++){
        list[i]=auxEmp[i];
    }
}

void hardcordSector(eSector sec[], int len){
    eSector auxSec[]={
        {1,     "Contabilidad"},
        {2, "Recursos Humanos"},
        {3,          "Legales"},
        {4,         "Sistemas"},
        {5,           "Ventas"}
    };
    for(int i=0; i<len; i++){
        sec[i]=auxSec[i];
    }
}

void initEmployees(eEmployee list[], int len){
    for(int i=0; i<len; i++){
        list[i].isEmpty = 0;
    }
}

int findFree(eEmployee list[], int len){
    int index = -1;

    for(int i=0; i<len; i++){
        if(list[i].isEmpty == 0){
            index = i;
            break;
        }
    }
    return index;
}

int findEmployee(eEmployee list[], int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].id == file)
        {
            index = i;
            break;
        }
    }

    return index;
}

void highEmployee(eEmployee list[], int len)
{
    int index;
    int file;
    int is;

    index = findFree(list, len);

    if( index == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &file);

        is = findEmployee(list, len, file);

        if( is != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", file);
            printEmployee(list[is]);
        }
        else
        {
            list[index].id = file;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(list[index].name);

            printf("Ingrese sueldo: ");
            scanf("%f", &list[index].salary );

            printf("Ingrese sector: ");
            scanf("%d", &list[index].sector);


            list[index].isEmpty = 1;

            printf("Alta empleado exitosa!!!\n\n");
        }
    }
}


void removeEmployee(eEmployee list[], int len)
{
    int file;
    char confirm;
    int is;

    printf("Ingrese legajo: ");
    scanf("%d", &file);

    is = findEmployee(list, len, file);

    if( is == -1)
    {
        printf("\nEl legajo %d no esta registrado en el sistema\n", file);
    }
    else
    {
        printEmployee(list[is]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirm = tolower(getche());

        if(confirm == 's')
        {
            list[is].isEmpty = 0;
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }
    }
}


void findEmployeeById(eEmployee list[], int len, int file){

    printf("Ingrese numero de legajo que desea encontrar: ");
    scanf("%d", &file);

    for(int i=0; i<len; i++){
        if(list[i].id == file && list[i].isEmpty == 1){
            printf(" Legajo      Nombre     Apellido    Sueldo        Sector\n");
            printf(" ------      ------     --------    ------        ------\n");
            printEmployee(list[i]);
            break;
        }
    }
}

/*int removeEmployee(eEmployee list[], int len, int id){
    int index = -1;

    printf("Ingrese numero de legajo: ");
    scanf("%d", &id);

    for(int i=0; i<len; i++){
        if(list[i].id == id && list[i].isEmpty == 1){
            list[i].isEmpty == 0;
            index = i;
        }
    }
    return index;
}*/


void modifyEmployee(eEmployee list[], int len)
{
    int file;
    char confirm;
    float nowSalary;
    int is;

    printf("Ingrese legajo: ");
    scanf("%d", &file);

    is = findEmployee(list, len, file);

    if( is == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", file);
    }
    else
    {
        findEmployee(list[]);

        printf("\nQuiere cambiar el sueldo? s/n");
        fflush(stdin);
        confirm = tolower(getche());

        if(confirm == 's')
        {
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &nowSalary);
            //valido sueldo
            list[is].salary = nowSalary;
        }
        else
        {
            printf("\nNo se ha modificado el sueldo\n");
        }
    }
}



void sortEmployeesUpward(eEmployee list[], int len){
        eEmployee auxChar;
        system("cls");
            for(int i=0; i<len-1; i++){
                for(int j=i+1; j<len; j++){
                    if(list[i].sector<list[j].sector){
                        auxChar = list[i];
                        list[i] = list[j];
                        list[j] = auxChar;
                    }
                }
                printEmployee(list[i]);
            }

            system("pause");
}

void printEmployee(eEmployee list){


    printf("   %d   %10s     %10s     %.2f         %d\n", list.id, list.name, list.lastName, list.salary, list.sector);

}

int printEmployees(eEmployee list[], int len){
    int contador = 0;

    system("cls");

    printf(" Legajo      Nombre     Apellido    Sueldo        Sector\n");
    printf(" ------      ------     --------    ------        ------\n");

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            printEmployee(list[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
    return 0;
}
