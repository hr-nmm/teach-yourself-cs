#include <stdio.h>
#include <stdlib.h>

FILE *infile;
FILE *outfile;

int main()
{
    infile = fopen("input.txt", "r"); // relative path name of file, read mode
    if (infile == NULL)
    {
        printf("Error: unable to open file %s\n", "input.txt");
        exit(1);
    }
    // fopen with absolute path name of file, write mode
    outfile = fopen("/home/kobe24/fun/teach-youtself-cs/0_Introduction_to_systems/02_C_deepDive/output.txt", "w");
    if (outfile == NULL)
    {
        printf("Error: unable to open outfile\n");
        exit(1);
    }
    int ch; // EOF is not a char value, but is an int.
    // since all char values can be stored in int, use int for ch
    ch = getc(infile);
    // read next char from the infile stream
    if (ch != EOF)
    {
        putc(ch, outfile); // write char value to the outfile stream
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}