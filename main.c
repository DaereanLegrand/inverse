#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int 
modulo(int a, int b)
{
    int res = a - ((a / b) * b);
    return res + (res < 0) * b;
}

int*
eucExt(int a, int b)
{
    int* res = (int*)malloc(sizeof(int) * 3);
    if (modulo(a, b) == 0) {
        res[0] = b;
        res[1] = 0;
        res[2] = 1;
        return res;
    } else {
        res = eucExt(b, modulo(a, b));
        int tempX = res[1];
        res[1] = res[2];
        res[2] = tempX - ((a / b) * res[2]);
        return res;
    }
}

int
inverse (int a, int b)
{
    int* tr = eucExt(a, b);
    if (tr[0] != 1) {
        puts("Error the provided numbers are not coprimes!");
        exit(-1);
    }
    return modulo(eucExt(a, b)[1], b);
}

int
main(int argc, char *argv[])
{
    if (argc == 2 && (!strcmp(argv[1], "-h") || (!strcmp(argv[1], "--help")))) {
        printf("Usage: inverse [-h] [--help] [num1 num2]\n");
    } else if (argc > 2) {
        int result = inverse(atoi(argv[1]), atoi(argv[2]));
        printf("Inverse of %s mod %s is: %d\n", argv[1], argv[2], result);
    }
    return 0;
}
