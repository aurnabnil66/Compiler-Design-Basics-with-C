#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    char c;
    
    f1 = fopen("input.c", "r");
    f2 = fopen("output.txt", "w");
    
    if (f1 == NULL)
    {
        printf("File Can't be opened\n");
    }
    
    int label = 0;
    int space = 0;
    
    while ((c = fgetc(f1)) != EOF)
    {
    
    label:
        if (c == '\n')
        {
            while ((c = fgetc(f1)) == ' ');
                
            goto label;
        }

        else if (c == '{')
        {
            fputc(c, f2);
            
            while ((c = fgetc(f1)) == ' ');
            goto label;
        }
       
        else if (c == ' ')
        {
            space++;

            if (space > 1)
            {
                continue;
            }
            else
            {
                fputc(c, f2);
            }
        }
        
        else if (c == '/')
        {
            c = fgetc(f1);
           
            if (c == '/')
            { 
                while (c = fgetc(f1) != '\n');
            }
            
            else if (c == '*')
            {
                while (c = fgetc(f1) != '/');
            }
        }
    
        else
        { 
            space = 0;
            fputc(c, f2);
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
