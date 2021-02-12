#include <stdio.h>
#include <cs50.h>
#include <string.h>

void pyramid(int height);

int main(void)
{
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (!(x >= 1 && x <= 8));

    pyramid(x);
}

void pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int column = 0; column < (height*2 + 2); column++)
        {
            if ((column + i) < (height - 1))
            {
                printf(" ");
            }
            else if (column == height || column == (height + 1))
            {
                printf(" ");
            }
            else if (column - i > height + 2)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

