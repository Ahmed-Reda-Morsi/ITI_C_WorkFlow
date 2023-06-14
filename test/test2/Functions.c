#include "../libs/STD_Types.h"
#include "Functions.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
// macros for define valid valid characters.
#define alpha_lower_begin 0x41 // 'a'
#define alpha_lower_end 0x5A   // 'z'
#define alpha_upper_begin 0x61 // 'A'
#define alpha_upper_end 0x7A   // 'Z'

u8 check_string(u8 *String)
{
    for (u8 i = 0; String[i] != '\0'; i++)
    {
        if (!(((String[i] >= alpha_lower_begin) && (String[i] <= alpha_lower_end)) || ((String[i] >= alpha_upper_begin) && (String[i] <= alpha_upper_end))))
        {
            return 0;
        }
    }

    return 1;
}

u8 Alphabetic_Order_String(u8 *String)

{
    u8 size = strlen(String); /* count the entered charaters for optimization  */
    u8 temp;                  // for swapping operation.
    if (!check_string(String))
    {
        return 0;
    }

    for (u8 i = 0; i < size; i++)
    {
        for (u8 j = 0; j < size - 1 - i; j++)
        {
            if (String[j] > *(String + j + 1))
            {
                temp = *(String + j);
                *(String + j) = *(String + j + 1);
                *(String + j + 1) = temp;
            }
        }
    }
    return 1;
}
//==============================================
u8 check_Plaindrome(u8 *Str, u8 string_size)
{
    u8 plaindrome_words = 0;
    u8 word_indexes[16] = {0};//word indexes array to save start and end for each word.
    u8 words_count = 0;
    u8 count = 0;  //  index of word indexes array.
    u8 *beg, *end;  // to check the word. 
    u8 i;
    for (i = 0; Str[i] != '\0'; i++)
    {
        if (Str[i] == ' ' && i != 0)
        {
            count++;
            word_indexes[count] = i - 1;
            count++;
            word_indexes[count] = i + 1;
            words_count++;
        }
    }
    word_indexes[count] = i - 1;
    words_count++;
    //-----------------------
    beg = &word_indexes[0];
    end = &word_indexes[1];
    u8 j = 0; 
    u8 flag = 0;
    while (j != words_count)
    {
     u8 word_size = *end - *beg;
        for (u8 i = 0; i < word_size/2; i++)
        {
            if (Str[*beg+i] != Str[*end - i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            plaindrome_words++;
        }
        else
        {
            flag = 0;
        }
        j++;
        beg += 2;
        end += 2;
    }

return plaindrome_words;
}

//==============  Cirular shift =================
u16 circular_shift(u16 num, u8 circular_type)
{
    u16 rotated_num = 0;
    if (circular_type == 'L')
    {
        u16 msb = num >> (sizeof(num) * 8 - 1);
        num = num << 1;
        rotated_num = num | msb;
    }
    else if (circular_type == 'R')
    {
        u16 lsb = num & 1;
        num = num >> 1;
        rotated_num = num | lsb;
    }
    return rotated_num;
};

//=================== Count zeros and ones =======================
u16 count_zeros_ones(u16 number, u8 value)
{
    value = value & 1;
    u16 counter = 0;
    for (u8 i = 0; i < sizeof(number) * 8; i++)
    {
        if (((number >> i) & (1)) == value)
        {
            counter++;
        }
    }
    return counter;
}

//==================== cubic root function=====================
f32 cubic_root(f32 number)
{
    return (pow(number, (1.0 / 3.0)));
    /*
    f32 i, precision = 0.0001;
    for (i = 1; (i * i * i) <= number; ++i);

    for (--i; (i * i * i) < number; i += precision);
    return i;
    */
}
//===========================================
void swap_two_bits(u16 *num1, u16 *num2, u8 bit_num)
{
    u16 num1_copy = *num1;
    u16 num2_copy = *num2;

    if (((num1_copy >> bit_num) & 1) == 1)
    {
        *num2 |= (1 << bit_num);
    }
    else
    {
        *num2 &= ~(1 << bit_num);
    }

    if (((num2_copy >> bit_num) & 1) == 1)
    {
        *num1 |= (1 << bit_num);
    }
    else
    {
        *num1 &= ~(1 << bit_num);
    }
}
//===================================================
u8 pairs_of_ones(u8 *array_bits, u8 array_size)
{
    u8 counter = 0;
    for (u8 i = 0; i < array_size - 3; i++)
    {
        if ((array_bits[i] == 0) && (array_bits[i + 1] == 1))
        {
            if ((array_bits[i + 2] == 1) && (array_bits[i + 3] == 0))
            {
                counter++;
            }
        }
    }

    return counter;
}