#include <stdio.h>

void print_blocks(int total_height);

int main(void)
{
    int total_height = 8;
    printf("Height: %i \n", total_height);
    print_blocks(total_height);
}

void print_blocks(int total_height)
{
    for (int column = 0; column < total_height; column++)
    {
        // prints the spaces
        for (int space = total_height - 1; space > column; space--)
        {
            printf(" ");
        }

        // prints the left blocks
        for (int left_blocks = -1; left_blocks < column; left_blocks++)
        {
            printf("#");
        }

        // two spaces between left and right blocks
        printf("  ");

        // prints the right blocks
        for (int right_blocks = -1; right_blocks < column; right_blocks++)
        {
            printf("#");
        }

        // go to the next column
        printf("\n");
    }
}