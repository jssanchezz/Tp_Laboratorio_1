#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    double A=0, B=0, X;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A=%.2lf)\n", A);
        printf("2- Ingresar 2do operando (B=%.2lf)\n", B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Ingrese 1er operando: ");
                scanf("%lf", &A);
                break;
            case 2:
                system("cls");
                printf("Ingrese 2do operando: ");
                scanf("%lf", &B);
                break;
            case 3:
                suma(A,B);
                break;
            case 4:
                resta(A,B);
                break;
            case 5:
                division(A,B);
                break;
            case 6:
                multiplicacion(A,B);
                break;
            case 7:
                system("cls");
                if(A<0)
                {
                    printf("Error, debe ingresar un numero positivo.\n");
                    system("pause");
                }
                else
                {
                    X=factorial(A);
                    printf("El factorial de %.0lf es: %.0lf\n", A, X);
                    system("pause");
                }

                break;
            case 8:
                suma(A,B);
                resta(A,B);
                division(A,B);
                multiplicacion(A,B);
                system("cls");
                if(A<0)
                {
                    printf("Error, debe ingresar un numero positivo para calcular el factorial.\n");
                    system("pause");
                }
                else
                {
                    X=factorial(A);
                    printf("El factorial de %.0lf es: %.0lf\n", A, X);
                    system("pause");
                }

                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
