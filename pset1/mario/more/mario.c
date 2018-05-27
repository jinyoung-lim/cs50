#include <stdio.h>
// cs50 library that has functions that collect
// input such as char, double, float, int, long long, string
#include <cs50.h>

int draw_pyramid_left(int row, int height);
int draw_pyramid_right(int row);

int main(void)
{
    // Fetch user height input and check for validity [0, 23]
    int userHeight;
    do
    {
        userHeight = get_int("Height: ");
    }
    while (0 > userHeight || userHeight > 23);

    // Handle edge cases when there is only one pyramid
    if (userHeight == 0)
    {
        printf("");
    }
    // [1, 23]
    else
    {
        for (int row = 0; row < userHeight; row++)
        {
            draw_pyramid_left(row, userHeight);
            printf("  ");
            draw_pyramid_right(row);
            printf("\n");
        }
    }
    return 0;
}

/**
 * Draws specified row of the left pyramid
 */
int draw_pyramid_left(int row, int height)
{
    //printf format string syntax: %[parameter][flags][width][.precision][length]type (https://en.wikipedia.org/wiki/Printf_format_string)
    int spaces = height - row - 1;
    int bricks = row + 1;
    // printf("spaces : %d  ,", spaces);   //DEBUG
    // printf("bricks : %d\n", bricks);    //DEBUG
    printf("%.*s", spaces, "                       ");
    printf("%.*s", bricks, "#######################");
    return 0;
}

/**
 * Draws specified row of the right pyramid
 */
int draw_pyramid_right(int row)
{
    int bricks = row + 1;
    // printf("spaces : %d  ,", spaces);   //DEBUG
    // printf("bricks : %d\n", bricks);    //DEBUG
    printf("%.*s", bricks, "#######################");
    return 0;
}
