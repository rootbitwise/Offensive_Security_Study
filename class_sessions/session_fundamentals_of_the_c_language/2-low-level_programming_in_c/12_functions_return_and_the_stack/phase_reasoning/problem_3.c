#include <stdio.h>
int main(void){
    {
int secret = 43; // the variable is declared and initialized
    }
printf("%d\n", secret); // printf trying to print a variable it cannot access
return 0;
}
/* This code will not compile, even though printf is inside the same scope as secret, the variable
 * secret is inside a different scope that limits its reach, so printf cannot interact with it
 * that is why it gives an error, printf cannot access the variable secret.
*/