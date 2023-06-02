#include <stdio.h>

int main(void)
{
    FILE *f1, *f2;
    char c;
    int headerFileFound;

    f1 = fopen("input.c", "r");
    f2 = fopen("output.txt", "w");

    if (!f1)
    {
        printf("File not found");
    }

    else
    {
        while ((c = fgetc(f1)) != EOF)
        {
            if (c == '#')
            {
                headerFileFound = 1;
                continue;

                if (headerFileFound)
                {
                    if ((c == '<'))
                    {
                        while ((c = fgetc(f1)) != '>')
                        {
                            fputc(c, f2);
                            printf("%c", c);
                        }
                        fputs("\n", f2);
                    }
                }
            }
        }
    }

    fclose(f1);
    fclose(f2);

    f2 = fopen("output.txt", "r");
    while ((c = fgetc(f1)) != EOF)
    {
        printf("%c", c);
    }
    
    fclose(f2);

    return 0;
}