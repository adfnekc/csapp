#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bits.c"
#include <ar.h>

typedef unsigned char *byte_pointer;

void u2bin(unsigned i)
{
    int c;
    int k;
    int n;
    for (c = 31; c >= 0; c--)
    {
        k = n >> c;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
}

int b2u(char *n)
{
    int bin, dec = 0;
    unsigned long len = strlen(n);
    printf("n:%s,len: %lu\n", n, len);

    for (int i = len - 1; i > -1; i--)
    {
        int a1 = (*"1");
        if (n[i] == a1)
            dec += pow(2, i);
    }

    printf("dec :%d", dec);
    return dec;
}

void test_allOddBits()
{
    int arr[] = {0xAAAAAAAA, 0xFFFFFFFD, -((1 << 31) + 1), 1, 0, -1, __INT_MAX__};
    int i = 0;
    size_t n = sizeof(arr) / sizeof(int);
    int (*f)(int) = allOddBits;
    for (i = 0; i < n; i++)
    {
        printf("x:%d,0x%X\t%d,0x%X\n", arr[i], arr[i], f(arr[i]), f(arr[i]));
    }
}

void main(int argc, char *argv[])
{
    b2u(argv[1]);
}
