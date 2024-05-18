#include <string.h>
#include <stdio.h>
#include <time.h>




int main(){

    srand(time(0));


    int number1 = (rand() % 6) + 1;

 
    printf("%d\n", number1);
  



    return 0;
}