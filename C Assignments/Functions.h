#include "../libs/STD_Types.h"

/* 
* @brief: take a string either than upper or lower case and assending it alphapetically
* @param:  string.
* @return: success -> 1 not success -> 0
 */
u8  Alphabetic_Order_String(u8* Str);  //problem1 

/* 
* @brief: take a string and check if it has any any special chatacters
* @param:  string.
* @return: success -> 1 (not has any special char.) not success -> 0 (has a special one.)
 */
u8 check_string(u8 *String);  //problem2


/* 
* @brief: take a integer and a Cirular shift 
* @param:  integer.
* @param:  type of Cirular shift (L-> left . R-> right ) .
* @return: integer after shifting.
 */
u16 circular_shift(u16 num, u8 circular_type);

/* 
* @brief: take a integer and counter the number of zeros or ones. 
* @param:  number .
* @param:  the value(1 or 0) if it greater than it will check the first bit.
* @return: the counter for the value.
 */
u16 count_zeros_ones(u16 number,u8 value);

/* 
* @brief: take a float number and return the cubic root of it. 
* @param: a float number.
* @return: the cubic root of it.
 */
f32 cubic_root(f32 number);

/* 
* @brief:  take two addresses of integers(u16) and swap a certain bit of them.. 
* @param:  number1.
* @param:  number2..
* @param:  bit number.
 */
void swap_two_bins(u16* num1,u16* num2,u8 bin_num);

/* 
* @brief:  take an array of bits and count the number of pairs of ones (0110).
* @param: an array of bits.
* @param: array size.
* @param: the number of pairs.
 */
u8 pairs_of_ones(u8* array_bits,u8 array_size);

/* 
* @brief: take a string of words separated with white spaces to count the plaindrome words ("modom").
* @param: a string of words.
* @param: size of string array.
* @return: number of plaindrome words.
 */
u8 check_Plaindrome(u8* Str,u8 string_size);