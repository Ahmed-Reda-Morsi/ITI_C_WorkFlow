#include "../../libs/STD_Types.h"
#include <stdlib.h>
#include <stdio.h>
#include "Queue_Array.h"

#define Queue_size 10

 s16 Queue[Queue_size] ={0};
 s8 Rear=-1;
 u8 Front=0;

u8 Queue_IsEmepty(void){
     if (Front>Rear)
    {
        return 1;
    }
    else {
        return 0;
    }
    
}

u8 Queue_IsFull(void){
   if (Rear== Queue_size-1)
   {
        return 1;
   }
   else{
    return 0;
   }
   
}

void EnQueue(s16 value){
    if (Queue_IsFull())
    {
        printf("Queue is Full !\n");
    }
    else{
        Rear++;
        Queue[Rear]=value;
    }
    
}

s16 DeQueue(void){
    s16 data=0;
    if (Queue_IsEmepty())
    {
        printf("Queue isEmepty !\n");
        exit(1);
    }
    else{
        data=Queue[Front];
        Front++;
    }

    if (Front>Rear)
    {
        Front=0;
        Rear=-1;
    }
    
 return data;
}

s16 Queue_Peek(void){
    if (Queue_IsEmepty())
    {
        printf("Queue isEmepty !\n");
        exit(1);
    }
    else{
        return Queue[Front];
       
    }
    
}


void Queue_Display(void){
    u8 index=Front;
    while (!Queue_IsEmepty()&&index<=Rear)
    {
        printf("\nQueue element %d : %d\n",index+1,Queue[index]);
        index++;
    }
}
