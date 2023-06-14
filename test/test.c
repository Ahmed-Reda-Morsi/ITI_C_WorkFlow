#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned char u8;
typedef unsigned short int u16;
#define alpha_lower_begin 0x41 // 'a'
#define alpha_lower_end 0x5A   // 'z'
#define alpha_upper_begin 0x61 // 'A'
#define alpha_upper_end 0x7A   // 'Z'
#define Number_begin 0x30      //'0'
#define Number_end 0x39        //'9'

// return 0 -> Not Valid | 1-> Valid.
u8 check_string(u8 *String)
{
    for (u8 i = 0; String[i] != '\0'; i++)
    {
        if (!(((String[i] >= alpha_lower_begin) && (String[i] <= alpha_lower_end)) || ((String[i] >= alpha_upper_begin) && (String[i] <= alpha_upper_end)) || String[i] == ' '))
        {
            return 0;
        }
    }

    return 1;
}
// return 0 -> Not Valid | 1-> Valid.
u8 check_PhoneNumber(u8 *String)
{
    u8 flag = 1,count=1;
    if (String[0] != '0'|| strlen(String)!=11)
    {
        flag = 0;
    }
    else
    {
        for (u8 i = 1; String[i] != '\0'; i++)
        {
            if (!((String[i] >= Number_begin) && (String[i] <= Number_end)))
            {
                count++;
            flag= 0;

            }
        }
    }
    return flag;
}
// return 0 -> Not Valid | 1-> Valid.
u8 check_Date_Of_Birth(u8 *String)
{
    u8 flag = 1;
    u8* ptr=strtok(String,"/");
    u16 day=atoi(ptr);
    ptr=strtok(NULL,"/");
    u16 month=atoi(ptr);
    ptr=strtok(NULL,"/");
    u16 year=atoi(ptr); 
    
    if (day==0||day>31)
    {
        flag=0;
    }
    else if (month==0||month>12)
    {
        flag=0;
    }
    else if (year==0||year>2017)   //  at least 6 years old 
    {
       flag=0;
    }
    return flag;
}
void main(void)
{
    //printf("%d",check_PhoneNumber("0v1145222009"));
    u8 date[13]="4/45/2014";
    printf("%d",check_Date_Of_Birth(date));
}