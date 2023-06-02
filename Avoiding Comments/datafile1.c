#include <stdio.h>

void check_comments(char);
void single_comments();
void block_comments();

FILE *f1, *f2;

int main(void)
{
    char c;

    f1 = fopen("input1.c", "r");
    f2 = fopen("output.txt", "w");

    if (!f1)
    {
        printf("File Not Found");
    }

    else
    {
        while ((c = fgetc(f1)) != EOF)
        {
            check_comments(c);
        }
    }

    fclose(f1);
    fclose(f2);

    return 0;
}

void check_comments(char c)
{
    if (c == '/')
    {
        char c1;

        if ((c1 = fgetc(f1)) == '*')
        {
            block_comments();
        }

        else if (c1 == '/')
        {
            single_comments();
        }

        else
        {
            fputc(c, f2);
            printf("%c", c);
            fputc(c1, f2);
            printf("%c", c1);
        }
    }

    else
    {
        fputc(c, f2);
        printf("%c", c);
    }
}

void single_comments()
{
    char c2;

    while ((c2 = fgetc(f1)) != EOF)
    {
        if (c2 == '\n')
        {
            return;
        }
    }
}

void block_comments()
{
    char c3, c4;

    while ((c3 = fgetc(f1)) != EOF)
    {
        if (c3 == '*')
        {
            c4 = fgetc(f1);

            if (c4 == '/')
            {
                return;
            }
        }
    }
}


