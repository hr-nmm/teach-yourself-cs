#include <stdio.h>
int main(int argc, char **argv)
{
    // Initialize a four-byte integer with easily distinguishable byte values
    int value = 0xAABBCCDD;
    // Initialize a character pointer to the address of the integer.
    char *p = (char *)&value;
    // For each byte in the integer, print its memory address and value.
    int i;
    for (i = 0; i < sizeof(value); i++)
    {
        printf("Address: %p, Value: %02hhX\n", p, *p);
        p += 1;
    }
    return 0;
}
/* op: is little endian
Address: 0x7fff077ea118, Value: DD
Address: 0x7fff077ea119, Value: CC
Address: 0x7fff077ea11a, Value: BB
Address: 0x7fff077ea11b, Value: AA
*/