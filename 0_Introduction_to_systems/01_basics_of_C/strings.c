#include <stdio.h>
#include <string.h>

void print_array(char arr[])
{
    int i;
    for (i = 0; i < strlen(arr); i++)
    {
        printf("%dth alphabet is: %c\n", i + 1, arr[i]);
    }
}
int main()
{
    int i;
    char ascii_of_a = 'a';
    char alphabets[26];
    for (i = 0; i < 26; i++)
    {
        alphabets[i] = ascii_of_a;
        ascii_of_a++;
    }
    print_array(alphabets);
    int s = strlen(alphabets);
    printf("%d\n", s);

    char str1[10], str2[12];
    str1[0] = 'h';
    str1[1] = 'i';
    str1[2] = '\0';
    printf("str1 is %s\n", (str1));
    printf("length of str1 is %ld\n", strlen(str1)); // 2
    str2[0] = 'f';
    str2[1] = 'r';
    str2[2] = 'i';
    str2[3] = 'e';
    str2[4] = 'n';
    str2[5] = 'd';
    str2[6] = '\0';
    printf("str2 is %s\n", (str2));
    printf("length of str2 is %ld\n", strlen(str2)); // 6

    char str3[100];
    printf("Enter a string\n");
    scanf("%[^\n]", str3);
    printf("str3 is %s of length %ld\n", str3, strlen(str3));
}