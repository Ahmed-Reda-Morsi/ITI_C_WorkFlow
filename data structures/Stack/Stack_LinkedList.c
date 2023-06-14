#include "../../libs/STD_Types.h"
#include "Stack_LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    u16 Data;
    struct Node *Next;
} Node_t;

Node_t *Top = NULL;



void Push(u16 value) 
{
    Node_t *new = (Node_t *)malloc(sizeof(Node_t));
    new->Data = value;
    if (Top == NULL)
    {
        new->Next = NULL;
        Top = new;
    }
    else
    {
        new->Next = Top;
        Top = new;
    }
}

void Pop(void)
{
    if (Top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        Node_t *ptr = Top;
        Top = Top->Next;
        free(ptr);
    }
}

void Display(void)
{
    Node_t *Temp = Top;
    while (Temp != NULL)
    {
        printf(" %d -->", Temp->Data);
        Temp = Temp->Next;
    }
}

void Search(u16 value)
{
    u8 flag = 0;
    Node_t *Temp = Top;
    while (Temp != NULL)
    {
        if (value == Temp->Data)
        {
            flag = 1;
            printf("Found ! \n");
            break;
        }
        Temp = Temp->Next;
    }
    if (flag == 0)
    {
        printf(" Not Found !\n");
    }
}