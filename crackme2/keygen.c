#include <stdio.h>

void display(char *s, int l)
{
    for(int i = 0; i < l; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    char key[10] = "abcdefghij";
    
    int dunno[8] = {0x45, 0xab, 0x36, 0xe3, 0x11, 0xcc, 0xc8, 0x00};
    int sum = 0;

    display(key, 10);

    for(int i = 0; i < 8; i++)
    {
        key[i] = key[i] ^ dunno[i];
    }
    display(key, 10);

    for(int i = 0; i < 8; i++)
    {
        sum = sum + (0xffffff00 | key[i]);
    } printf("%d\n", sum);

    return 0;
}
