#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct student
{
    char name[20];
    int age;
    char sex;
    int marks_out_of_10[5];
    char hobby[20];
    bool is_indian;
};
void print_array(int arr[]);
void print_struct_student(struct student ds);

int main()
{
    struct student kobe;
    printf("size of struct student is %ld\n", sizeof(struct student)); // 72 bytes
    printf("Enter Student's name,age,sex(in order respectively): \n");
    scanf("%[^\n] %d %c", kobe.name, &kobe.age, &kobe.sex);
    strcpy(kobe.hobby, "guitar playing");
    kobe.marks_out_of_10[0] = 6;
    kobe.marks_out_of_10[2] = 8;
    kobe.marks_out_of_10[1] = 7;
    kobe.marks_out_of_10[3] = 9;
    kobe.marks_out_of_10[4] = 10;
    kobe.is_indian = false;

    print_struct_student(kobe);

    struct student mj;
    mj = kobe;
    strcpy(mj.name, "Michael Jordan");
    mj.marks_out_of_10[2] = 10;

    print_struct_student(mj);

    return 0;
}

void print_array(int arr[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("marks for subect code %d is: %d/10\n", 3001 + i, arr[i]);
    }
}

void print_struct_student(struct student ds)
{
    printf("Full Name: %s\n", ds.name);
    printf("Age: %d\n", ds.age);
    printf("Sex: %c\n", ds.sex);
    printf("Hobby: %s\n", ds.hobby);
    printf("Is indian: %s\n", ds.is_indian ? "true" : "false");
    print_array(ds.marks_out_of_10);
}
