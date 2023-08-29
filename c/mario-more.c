#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // prompt user for number 1-8 for height of pyramid, variable h
    // and check that number is valid, 1-8
    int h;
    do
    {
        h = get_int("Please provide a number from 1-8  ");
    }
    while (h < 1 || h > 8);


    // declare row variable r to run h number of rows and used to calc spaces and hashmarks on rows
    for (int r = 0; r < h; r++)
    {
        // declare spaces variable sl to input spaces in each row left side, row n has h-n spaces
        for (int sl = r; sl < h - 1; sl++)
        {
            printf(" ");
        }
        // declare hashtag variable htl to input hashtags in each row left side, row n has n hasgtags
        for (int htl = 0; htl < r + 1; htl++)
        {
            printf("#");
        }
        // print 2 spaces between pyramids
        printf("  ");

        // declare hashtag variable hsr to input hashtags in each row right side, row n has n hashtags
        // same amount of hashtags as the left pyramid
        for (int htr = 0; htr < r + 1; htr++)
        {
            printf("#");
        }
   
        printf("\n");
    }

}
