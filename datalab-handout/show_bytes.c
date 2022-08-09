#include <stdio.h>
#include <string.h>
#include <math.h>
#include "bits.c"

typedef unsigned char *byte_pointer;
double pow(double __x, double __y);
int isLessOrEqual(int, int);

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
    int dec = 0;
    unsigned long len = strlen(n);
    printf("n:%s,len: %lu\n", n, len);

    for (int i = len - 1; i > -1; i--)
    {
        int a1 = (*"1");
        // printf("%c,%d\n", n[i], dec);
        if (n[i] == a1)
        {
            double d = pow(2, len - i - 1);
            dec += d;
        }
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

void test_isLessOrEqual()
{
    int arr[][2] = {0xAAAAAAAA, 0xFFFFFFFD, -3, 1, -1, 0, 0, 0, 1, 5, 0xFFFFFFFD, 0xAAAAAAAA, 1, -3, 0, -1, 5, 1, 0x80000000, 0x7fffffff, 0x80000000, 0x7ffffffe, 0x7fffffff, 0x80000000};
    int result[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0};
    int i = 0;
    size_t n = sizeof(result) / sizeof(int);
    for (i = 0; i < n; i++)
    {
        int f = isLessOrEqual(arr[i][0], arr[i][1]);
        if (f != result[i])
        {
            printf(" * %d[0x%X] %d[0x%X] %d[0x%X], result should be %d\n", arr[i][0], arr[i][0], arr[i][1], arr[i][1], f, f, result[i]);
        }
        else
        {
            printf("%d[0x%X] %d[0x%X] %d[0x%X], result should be %d\n", arr[i][0], arr[i][0], arr[i][1], arr[i][1], f, f, result[i]);
        }
    }
}

int main(int argc, char *argv[])
{
    test_isLessOrEqual();
}
