#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void suma(double x, double y)
{
    system("cls");
    printf("La suma de sus operando es: %.2lf\n\n", x+y);
    system("pause");
}

void resta(double x, double y)
{
    system("cls");
    printf("La resta de sus operando es: %.2lf\n\n", x-y);
    system("pause");
}

void division(double x, double y)
{
    system("cls");
    if(y==0)
    {
        printf("La division por 0 (cero) es indeterminada.\n\n");
        system("pause");
    }
    else
    {
        printf("La division de sus operando es: %.2lf\n\n", x/y);
        system("pause");
    }
}

void multiplicacion(double x, double y)
{
    system("cls");
    printf("La multiplicacion de sus operando es: %.2lf\n\n", x*y);
    system("pause");
}

double factorial(double x)
{
    double resultado;

        if(x==0)
        {
            resultado=1;
        }
        else
        {
            resultado=x*factorial(x-1);
        }
        return resultado;


}
#endif // FUNCIONES_H_INCLUDED
