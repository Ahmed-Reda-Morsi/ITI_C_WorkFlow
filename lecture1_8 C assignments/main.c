#include <stdio.h>
#include <stdlib.h>
#include "../libs/STD_Types.h"
#define Array_size 10

int main()
{
    s16 arr[Array_size];

    for (u8 i = 0; i < Array_size; i++)
    {
        scanf("%d ", (arr + i));
    }
    printf("%d\n", arr[5]); 

    for (u8 i = 0; i <Array_size; i++)
    {
        for (u8 j = 0; j < Array_size-1-i; j++)
        {
            if (*(arr+j)>*(arr+1+j))
            {
                s16 temp=*(arr+j);
                *(arr+j)=*(arr+1+j);
                *(arr+1+j)=temp;
            }
            
        }
        
    }
 
    printf("min:%d || max: %d \n",*(arr),*(arr+Array_size-1));
    printf("the defference : %d \n",*(arr+Array_size-1)-*(arr));
    

}
