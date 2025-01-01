#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void get_integer(char *str, long int *n)
{
    bool valid = false;
    char input[1000];
    while (!valid)
    {
        printf("%s", str);
        fgets(input, 1000, stdin);
        input[strlen(input) - 1] = '\0';
        if (strlen(input) == 0)
        {
            printf("!!! Invalid Input !!!\n");
            printf("    Try Again\n");
            continue;
        }
        bool notint = false;
        int dots = 0;
        for (int i = 0; i < strlen(input); i++)
        {
            if (!(isdigit(input[i]) || (input[i] == '-' && i == 0)))
            {
                notint = true;
                break;
            }
        }
        if (notint)
        {
            printf("!!! Invalid Input !!!\n");
            printf("    Try Again\n");
        }
        else
        {
            if (atof(input) > pow(2, 63) - 1)
            {
                printf("!!! OVERFLOW: NUMBER IS SO BIG !!!\n");
                printf("    Try Again\n");
                continue;
            }
            valid = true;
        }
    }
    *n = atol(input);
}

void get_double(char *str, double *n)
{
    bool valid = false;
    char input[1000];
    while (!valid)
    {
        printf("%s", str);
        fgets(input, 1000, stdin);
        if (input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
        if (strlen(input) == 0)
        {
            printf("!!! Invalid Input !!!\n");
            printf("    Try Again\n");
            continue;
        }
        bool notdouble = false;
        int dots = 0;
        for (int i = 0; i < strlen(input); i++)
        {
            if (input[i] == '.')
            {
                dots++;
                if (dots > 1)
                {
                    notdouble = true;
                    break;
                }
            }
            if (!(isdigit(input[i]) || input[i] == '.' || (input[i] == '-' && i == 0)))
            {
                notdouble = true;
                break;
            }
        }
        if (notdouble)
        {
            printf("!!! Invalid Input !!!\n");
            printf("    Try Again\n");
        }
        else
            valid = true;
    }
    *n = atof(input);
}

void get_positive_integer(char *str, long int *n)
{
    do
    {
        get_integer(str, n);
        if (*n <= 0)
            printf("!!! This Number Can't Be negative or Zero !!!\n    Try Again\n");
    } while (*n <= 0);
}

int main()
{
    double decimal;
    get_double("Enter decimal number : ", &decimal);
    printf("decimal number : %lf\n", decimal);
    long int num;
    get_integer("Enter integer number : ", &num);
    printf("Integer number : %d\n", num);
}