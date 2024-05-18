#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){

    int num1;
    int num2;
    int result;
    char operator_char;

    printf("select a number: ");
    scanf("%d \n", &num1);

    printf("select another number: ");
    scanf("%d \n", &num2);

    printf("select the operator: ");
    scanf("%c \n", &operator_char);


    switch (operator_char)
    {
    case '+':
    result = num1 + num2;
        break;
    case '-':
    result = num1 - num2;
    break;
    case '*':
    result = num1 * num2;
    break;
    case '/':
    result = num1 / num2;
    break;    
    
    default:
    printf("this operator does not exist");
        break;
        return 1;
    }


    printf("%d \n", result);



    return 0;
}





