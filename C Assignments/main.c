#include <stdio.h>
#include "../libs/STD_Types.h"
#include "Functions.h"
#define string_size 50 // assumed maximum size of the entered string.

/* Write a program to re-arrange the string in alphabetic order */
// problem 1
// #define problem_1 //*! To run uncomment

/* write a program to check if the string passed by the user has all alphabetic characters or not.
capital or small characters are allowed */
//  problem 2
// #define problem_2 //*!To run uncomment

/* circular_shift for and integer. */
// problem 3
// #define problem_3 //*!To run uncomment

/* count the number of zeros or ones. */
// problem 4
// #define problem_4 //*!To run uncomment

/* get cubic root for number. */
// problem 5
// #define problem_5  //*!To run uncomment

/* swap two bits */
// problem 6
//#define problem_6 //*!To run uncomment

/* count numbers of 0110 in q array or bits. */
// problem 7
//#define problem_7 //*!To run uncomment

/* count the plaindrome words in a string. */
// problem 8
#define problem_8 //*!To run uncomment

void main(void)
{

#ifdef problem_1
    u8 str[string_size];
    printf("enter the string to be oreded\n");
    scanf("%[^\n]", str);
    if (Alphabetic_Order_String(str))
        printf(" Oreded: %s\n", str);
    else
        printf("Not valid String!!\n");

#elif defined problem_2
    u8 str[string_size];
    printf("enter the string to check it.\n");
    scanf("%[^\n]", str);
    if (check_string(str))
        printf(" this string (%s) is valid \n", str);
    else
        printf("Not valid String!!\n");

#elif defined problem_3
    u16 integer = 0x0002;
    printf("shifted intger to right: %x\n", circular_shift(integer, 'R'));
    printf("shifted intger to to left: %x\n", circular_shift(integer, 'L'));

#elif defined problem_4
    u16 integer = 0x0f0f;
    printf("number or zeros: %d\n", count_zeros_ones(integer, 0));
    printf("number or ones: %d\n", count_zeros_ones(integer, 1));

#elif defined problem_5
    u16 integer = 15;
    printf("cubic root is : %f\n", cubic_root(integer));

#elif defined problem_6
    u16 num1 = 0xf7;
    u16 num2 = 0x08;
    swap_two_bits(&num1, &num2, 3);
    printf("num1: %d \nnum2: %d\n", num1, num2);

#elif defined problem_7
    u8 num[15]={0,1,1,0,1,1,0,1,1,1,0,1,1};
    printf("number of pairs: %d\n",pairs_of_ones(num, 15));

#elif defined problem_8
    u8 str[string_size];
    printf("enter the string\n");
    scanf("%[^\n]", str);
    printf("plaindrome words: %d\n",check_Plaindrome(str,string_size));
#endif
    //----------------------------------------------------------------
}
