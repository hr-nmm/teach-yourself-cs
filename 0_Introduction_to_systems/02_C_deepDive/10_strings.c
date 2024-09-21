#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int size;
    char str[64];
    // statically allocated
    char *new_str = NULL; // for dynamically allocated
    strcpy(str, "Hello");
    size = strlen(str);
    // returns 5
    new_str = malloc(sizeof(char) * (size + 1)); // need space for '\0'
    if (new_str == NULL)
    {
        printf("Error: malloc failed! exiting.\n");
        exit(1);
    }
    strcpy(new_str, str);
    printf("%s %s\n", str, new_str);
    // prints "Hello Hello"
    strcat(new_str, " There"); // concatenate " There" to the end of str
    printf("%s\n", new_str);
    // prints "Hello There"
    free(new_str); // free malloc'ed space when done
    new_str = NULL;

    char str1[64];
    float ave = 76.8;
    int num = 2;
    // initialize str to format string, filling in each placeholder with
    // a char representation of its arguments' values
    sprintf(str1, "%s is %d years old and in grade %d", "Henry", 12, 7);
    printf("%s\n", str1); // prints: Henry is 12 years old and in grade 7
    sprintf(str1, "The average grade on exam %d is %g", num, ave);
    printf("%s\n", str1); // prints: The average grade on exam 2 is 76.8
    return 0;
}