int main()
{
    int x, y;
    x = 1;
    x = x + 2;
    x = x - 14;
    y = x * 100;
    x = x + y * 6;
    return 0;
}
// $ gcc -m32 -S simpleops.c  # runs the assembler to create a .s text file
//$ gcc -m32 -c simpleops.s   # compiles to a relocatable object binary file (.o)
// gcc -m32 -o simpleops simpleops.o # creates a 32-bit executable file