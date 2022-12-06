#include <stdio.h>

int X(int a, int b);

int main()
{

int num1, num2, resp;

printf("Digite dois valores separados por espaço:\n");

scanf("%d %d", &num1, &num2);

resp = X(num1, num2);

printf("Resposta: %d\n", resp);

return 0; }


int X(int num1, int num2){
    
if (num1>= num2)
{
return num1;
}else{

return num2;
}
}