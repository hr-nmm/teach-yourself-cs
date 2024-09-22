#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct studentT
{
    char name[64];
    int age;
    float gpa;
    int grad_yr;
};

// think very carefully about the type of each field when
// accessing it (name is an array of char, age is an int ...)
int main()
{
    struct studentT s;
    struct studentT *sptr;
    strcpy(s.name, "Freya");
    s.age = 18;
    s.gpa = 4.0;
    s.grad_yr = 2020;
    // malloc space for a struct studentT for sptr to point to:
    sptr = malloc(sizeof(struct studentT));
    if (sptr == NULL)
    {
        printf("Error: malloc failed \n");
        exit(1);
    }
    // the grad_yr field of what sptr points to gets 2021:
    (*sptr).grad_yr = 2021;
    // the age field of what sptr points to gets s.age plus 1:
    (*sptr).age = s.age + 1;

    // the gpa field of what sptr points to gets 3.5:
    sptr->gpa = 3.5;
    // the name field of what sptr points to is a char *
    // (can use strcpy to init its value):
    strcpy(sptr->name, "Lars");
    printf("name of student stored in heap is %s", sptr->name); // Lars

    return 0;
}
