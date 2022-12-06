#include

int main()

{

int *ip;

int i, arr[2][2] = {8, 10, 12, 13};

ip = *arr ;

printf("%d ", *(ip+2));

return 0;

}