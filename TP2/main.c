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
int addEmployee(eEmployee list[], int len);
int findEmployeeById(eEmployee list[], int len, int id);
int removeEmployee(eEmployee list[], int len, int id);
void hardcordEmployee(eEmployee list[], int len);
void hardcordSector(eSector sec[], int len);
void initEmployees(eEmployee list[], int len);
void sortEmployees(eEmployee list[], int len, int order);


int main()
{
    char seguir = 's';
    char confirmar;

    eEmployee employee[SIZEEMP];
    eSector sectors[SIZESEC];
//-----------------------LLAMADA DE FUNCIONES-----------/
    hardcordEmployee(employee, SIZEEMP);
    hardcordSector(sectors, SIZESEC);
 // initEmployees(employee, SIZEEMP);

    do
    {
        switch(menu())
        {
        case 1:
            printf("\nAlta empleado\n");
            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n");
            system("pause");
            break;

        case 3:
            printf("\nModificar empleado\n");
            system("pause");
            break;
        case 4:
            menuInfo();
            system("pause");
            break;

        case 5:
            printf("\nConfirmar salida ??  S o N: ");
            fflush(stdin);
            confirmar = getche();

            if(tolower(confirmar) == 's'){
                seguir = 'n';
            }
            break;

        default:
            printf("Opcion invalida");
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
    printf("4- Informar\n");
    printf("5- Salir\n\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &option);

    return option;
}

int menuInfo(){
    int option;
    system("cls");
    printf("\n************* ORDENAR EMPLEADOS *************\n\n");
    printf("1- Alfabeticamente por Apellido y Sector\n");
    printf("2- Total de empleados, promedio de sueldo, y quienes lo superan\n\n");
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
        {14, "Ezequiel",   "Posta",  35000, 4, 1},
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

int addEmployee(eEmployee list[], int len){
    int index = -1;

    for(int i=0; i<len; i++){
        if(list[i].isEmpty == 0){
            index = i;
            break;
        }
    }
    return index;
}

int findEmployeeById(eEmployee list[], int len, int id){
    int index = -1;

    for(int i=0; i<len; i++){
        if(list[i].id == id && list[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int removeEmployee(eEmployee list[], int len, int id){
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
}

void sortEmployees(eEmployee list[], int len, int order){
   eEmployee auxChar;

        if(order == 1){
            for(int i=0; i<len; i++){
                for(int j=0; j<len; j++){
                    if(list[i].sector<list[j].sector){
                        auxChar = list[i];
                        list[i] = list[j];
                        list[j] = auxChar;
                    }
                }
            }
        }else{
            for(int i=0; i<len; i++){
                for(int j=0; j<len; j++){
                    if(list[i].sector>list[j].sector){
                        auxChar = list[i];
                        list[i] = list[j];
                        list[j] = auxChar;
                    }
                }
            }
        }
}


