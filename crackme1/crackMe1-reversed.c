#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 5;
    int b = 7;
    int c = 45;

    int user;
    printf("Password: ");
    scanf("%d", &user);

    if(user == c*(a+b))
    {
    	printf("Good password\n");
    }
    else
    {
    	printf("Bad password\n");
    }
    return 0;
}
