#include <stdio.h>

int main(void)
{
    int *a, *b, c, d;
    printf("Enter first number: ");
    scanf("%d", &c);
    printf("Enter second number: ");
    scanf("%d", &d);
    a = &c;
    b = &d;
    if (*a > *b)
    {
        printf("%d is the maximum number", *a);
    }
    else if (*b > *a)
    {
        printf("%d is the maximum number", *b);
    }
    else
    {
        printf("Both inputs are the same");
    }
}