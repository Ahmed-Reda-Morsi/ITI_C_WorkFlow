#include<stdio.h>
#include <stdlib.h>
#include "../../libs/STD_Types.h"

typedef struct Node
{
    u16 Data;
    struct Node *Next;
} Node_t;

Node_t *Front = NULL;
Node_t *Rear = NULL;

u8 Queue_IsEmepty(void){
     if (Front==NULL&&Rear==NULL)
    {
        return 1;
    }
    else {
        return 0;
    }
    
}
void EnQueue(s16 value){
    Node_t* new=(Node_t*)malloc(sizeof(Node_t));
    new->Data=value;
    new->Next=NULL;
    if (Front==NULL&&Rear==NULL)
    {
        Front=Rear=new;

    }
    else{
        Rear->Next=new;
        Rear=new;

    }
    
    
}
s16 DeQueue(void){
    s16 data=0;
    Node_t* temp;
    if (Queue_IsEmepty())
    {
        printf("Queue isEmepty !\n");
        exit(1);
    }
    else{
       temp=Front;
       data=Front->Data;
       Front=Front->Next;
       free(temp);
    }  
 return data;
}
void Queue_Display(void){
   Node_t* temp=Front;
    while (temp!=NULL)
    {
        printf("\nQueue element: %d\n",temp->Data);
        temp=temp->Next;
       
    }
}
