#include <stdio.h>
#include <string.h>
#include "bits.c"
#include <ar.h>

typedef unsigned char *byte_pointer;

void ui2bin(unsigned i)
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
    ui2bin(0xAAAAAAAA);
}
