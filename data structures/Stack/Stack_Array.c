#include "../../libs/STD_Types.h"
#include <stdio.h>
#include <stdlib.h>
#include "Stack_Array.h"


#define Stack_MaxSize 10
s8 TOP = -1;
u32 stack[Stack_MaxSize];


u8 IsFull(void)
{
    if (TOP == Stack_MaxSize - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
u8 IsEmpty(void)
{
    if (TOP == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
u8 Push(u32 data)
{
    if (!IsFull())
    {
        TOP++;
        stack[TOP] = data;
        return 1;
    }
    else
    {
        printf("stack is full! \n");
        return -1;
    }
}

u32 Pop(void)
{
    if (IsEmpty() == 1)
    {
        printf("Could not retrieve data,Stack is empty !");
        exit(1);
    }
    else
    {
        u32 Last_Element = stack[TOP];
        stack[TOP] = 0;
        TOP--;
        return (Last_Element);
    }
}

u32 Peek(void)
{
    if (!IsEmpty())
    {
        return (stack[TOP]);
    }
    else
    {
        printf("Stack is empty !");
        exit(1);
    }
}
void Display(void)
{
  /*
    for (u32 i = 0; i < Stack_MaxSize; i++)
    {
        printf("element %d :%d\n", i + 1, stack[i]);
    }
    printf("the Top is : %d\n", TOP);
     */
    while (!IsEmpty())
    {
        printf("element %d: %ld\n", TOP + 1, Pop());
    }

}