#include "stdio.h"
#include "../include/str.h"

//First and second functions in the tests use strcmp function. I think it is OK in case strcmp function returns correct answers for tests independently any other function.
//Also result of them is writing down for each test so user can find misstake by his own eyes. Also using in strcmp second arguments of function strcpy is ok, be cause it is const.

void test_strcpy(){
    printf("\nStart testing: \n");
    printf("\nStart testing strcpy function\n");
    
    char a[] = "aa";
    char b[] = "aaa";
    printf("First test: 'aa' <-- 'aaa' changes 'aa' to 'aaa'\n");
    if (!strcmp(strcpy(a, b), b)) printf("OK. Answer: ");
    else printf("NOT OK. Function works incorrectly, result: ");
    printf("%s\n", a);

    char c[] = "aa";
    char d[] = "";
    printf("Second test: 'aa' <-- '' changes 'aa' to ''\n");
    if (!strcmp(strcpy(c, d), d)) printf("OK. Answer: ");
    else printf("NOT OK. Function works incorrectly, result: ");
    printf("%s\n", c);

    char e[] = "";
    char f[] = "  a a a a";
    printf("Third test: '' <-- '  a a a a' changes '' to '  a a a a'\n");
    if (!strcmp(strcpy(e, f), f)) printf("OK. Answer: ");
    else printf("NOT OK. Function works incorrectly, result: ");
    printf("%s\n", e);
}

void test_strcat(){
    printf("\nStart testing strcat function\n");
    
    char a[] = "aaa";
    char b[] = "aaa";
    printf("First test: 'aaa' + 'aaa' = 'aaaaaa'\n");
    if (!strcmp(strcat(a, b), "aaaaaa")) printf("OK. Answer: ");
    else printf("NOT OK. Answer in not equal 'aaaaaa'. Function works incorrectly, result: ");
    printf("%s\n", a);

    char c[] = "abc";
    char d[] = "defgh";
    printf("Second test: 'abc' + 'defgh' = 'abcdefgh'\n");
    if (!strcmp(strcat(c, d), "abcdefgh")) printf("OK. Answer: ");
    else printf("NOT OK. Answer in not equal 'abcdefgh'. Function works incorrectly, result: ");
    printf("%s\n", c);

    char e[] = "";
    char f[] = "d";
    printf("Third test: '' + 'd' = 'd'\n");
    if (!strcmp(strcat(e, f), "d")) printf("OK. Answer: ");
    else printf("NOT OK. Answer in not equal 'd'. Function works incorrectly, result: ");
    printf("%s\n", e);

    char h[] = "";
    char i[] = "";
    printf("Fourth test: '' + '' = ''\n");
    if (!strcmp(strcat(h, i), "")) printf("OK. Answer: ");
    else printf("NOT OK. Answer in not equal ''. Function works incorrectly, result: ");
    printf("%s\n", h);
}

void test_strcmp(){
    printf("\nStart testing strcmp function\n");

    printf("First test: 'aaa' = 'aaa'\n");
    if (strcmp("aaa", "aaa") == 0) printf("OK. Answer: 'aaa' is eqaul 'aaa'.\n");
    else printf("NOT OK. Strings are equal but function returns not zero. Function works incorrectly\n");
    

    printf("Second test: 'aab' < 'aaa'\n");
    if (strcmp("aaa", "aab") < 0) printf("OK. Answer 'aaa' is lower than 'aab'.\n");
    else printf("NOT OK. Function returns number greater or equal than zero. Function works incorrectly\n");

    printf("Third test: 'aabasaasasas' > 'aaa'\n");
    if (strcmp("aabasaasasas", "aab") > 0) printf("OK. Answer 'aabasaasasas' is greater than 'aab'.\n");
    else printf("NOT OK. Function returns number lower or equal than zero. Function works incorrectly\n");
    
}

void test_strlen(){
    printf("\nStart testing strlen function\n");

    printf("First test: length of 'aaa' is 3\n");
    printf("Result of the first test: ");
    if (strlen("aaa") == 3) printf("OK. answer for first test is 3.\n");
    else printf("NOT OK. Answer for the first test is not equl 3. Function works incorrectly\n"); 
 
    printf("Second test: length of '3.1415' is 6\n");
    printf("Result of the second test: ");
    if (strlen("3.1415") == 6) printf("OK. answer for the second test is 6.\n");
    else printf("NOT OK. Answer for the second test is not equal 6. Function works incorrectly\n");

    printf("Third test: length of '' is 0\n");
    printf("Result of the third test: ");
    if (strlen("") == 0) printf("OK. answer for the third test is 0.\n");
    else printf("NOT OK. Answer for the third test is not equl 0. Function works incorrectly\n");
}
