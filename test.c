
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Booleanos
#include <stdlib.h>

#include <unistd.h>
#include <limits.h>

int main()
{
    char *name = "/testfile.txt";
    char cwd[10000];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("INFO - DEBUG: Current working dir: %s\n", cwd);
    }
    else
    {
        perror("INFO - DEBUG: getcwd() error");
        return 1;
    }

    char *filename = strcat(cwd,name);

    printf("INFO - DEBUG: Filename %s", filename);
    FILE *fp = fopen(filename, "r");




    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    // close the file
    fclose(fp);

    return 0;
}
